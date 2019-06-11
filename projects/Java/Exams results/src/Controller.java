package lab13_package;

import org.w3c.dom.Document;
import org.xml.sax.ErrorHandler;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;

import javax.swing.*;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import java.awt.*;
import java.io.*;
import java.util.*;

public class Controller
{
    SessionDatabase model;
    MainFrame view;

    int targetSemester;
    TreeSet<String> targetSubjects = new TreeSet<>();

    Controller(SessionDatabase model)
    {
        this.model = model;

        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader("input.txt"));
            int num;
            String name;
            int sem;
            String subject;
            int mark;

            String s;
            while ((s = bufferedReader.readLine()) != null) {
                StringTokenizer tok = new StringTokenizer(s, " \t");
                num = Integer.parseInt(tok.nextToken());
                name = tok.nextToken();
                sem = Integer.parseInt(tok.nextToken());
                subject = tok.nextToken();
                mark = Integer.parseInt(tok.nextToken());
                this.model.add(new SessionEntry(num, name, sem, subject, mark));
            }
        }
        catch (IOException e) {}
     }

    void readData() {
        try {
            FileDialog fileDialog = new FileDialog(view, "Open", FileDialog.LOAD);
            fileDialog.setVisible(true);

            if (fileDialog.getFile() == null)
                return;

            String path = fileDialog.getDirectory() + fileDialog.getFile();
            FileInputStream fis = new FileInputStream(path);
            ObjectInputStream ois = new ObjectInputStream(fis);

            SessionDatabase temp = (SessionDatabase)ois.readObject();
            model.clear();
            model.addAll(temp);

            if (view.show) {
                findNotPassed(false);
            }
            view.repaint();

        }
        catch (IOException | ClassNotFoundException e) {
            JOptionPane.showMessageDialog(null, e, "Exception", JOptionPane.ERROR_MESSAGE);
        }
    }

    void readXMLData()
    {
        try
        {
            FileDialog fileDialog = new FileDialog(view, "Open XML file", FileDialog.LOAD);
            fileDialog.setDirectory(System.getProperty("dir"));
            fileDialog.setFilenameFilter((dir, name) -> name.endsWith(".xml"));
            fileDialog.setVisible(true);

            if (fileDialog.getFile() == null)
                return;

            MyXMLParser myXMLParser = new MyXMLParser();
            myXMLParser.readData(new File(fileDialog.getDirectory() + fileDialog.getFile()), model);
        }
        catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Ошибка чтения файла", "Exception", JOptionPane.ERROR_MESSAGE);
        }
        catch (ParserConfigurationException | SAXException e) {
            JOptionPane.showMessageDialog(null, "Файл не соответствует формату", "Exception", JOptionPane.ERROR_MESSAGE);
        }

        if (view.show) {
            findNotPassed(false);
        }
        view.repaint();
    }

    void writeData()
    {
        try {
            FileDialog fileDialog = new FileDialog(view, "Save", FileDialog.SAVE);
            fileDialog.setVisible(true);

            if (fileDialog.getFile() == null)
                return;

            String path = fileDialog.getDirectory() + fileDialog.getFile();
            FileOutputStream fos = new FileOutputStream(path);
            ObjectOutputStream oos = new ObjectOutputStream(fos);

            oos.writeObject(model);
            oos.flush();
            oos.close();
            fos.close();
        }
        catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Serialization failed", "Exception", JOptionPane.ERROR_MESSAGE);
        }
    }

    void writeXMLData()
    {
        try
        {
            FileDialog fileDialog = new FileDialog(view, "Save as XML", FileDialog.SAVE);
            fileDialog.setDirectory(System.getProperty("dir"));
            fileDialog.setFilenameFilter((dir, name) -> name.endsWith(".xml"));
            fileDialog.setVisible(true);

            if (fileDialog.getFile() == null)
                return;

            MyXMLParser myXMLParser = new MyXMLParser();
            myXMLParser.writeData(new File(fileDialog.getDirectory() + fileDialog.getFile()), model);
        }
        catch (ParserConfigurationException | TransformerException e) {
            JOptionPane.showMessageDialog(null, "Файл не соответствует формату", "Exception", JOptionPane.ERROR_MESSAGE);
        }
    }

    void addItem(AddItemDialog dialog)
    {
        try {
            int number = Integer.parseInt(dialog.numberField.getText());
            String surname = dialog.surnameField.getText();
            int semester = Integer.parseInt(dialog.semesterField.getText());
            String subject = dialog.subjectField.getText();
            int mark = Integer.parseInt(dialog.markField.getText());

            model.add(new SessionEntry(number, surname, semester, subject, mark));
            dialog.setVisible(false);
            view.repaint();
            JOptionPane.showMessageDialog(null, "Added successfully", "", JOptionPane.INFORMATION_MESSAGE);

            if (view.show) {
                findNotPassed(false);
            }
        }
        catch (IllegalArgumentException e) {
            JOptionPane.showMessageDialog(null, e, "Exception", JOptionPane.ERROR_MESSAGE);
        }
    }

    void removeItem()
    {
        if (model.isEmpty() || view.entryList.isSelectionEmpty() || view.entryList.isSelectedIndex(model.size()))
            return;
        if (model.removeAll(view.entryList.getSelectedValuesList())) {
            view.resultList.setListData(new Vector());
            view.repaint();
            if (view.show) {
                findNotPassed(false);
            }
        }
    }

    void changeCriterion()
    {
        String s;
        while (true) {
            try {
                s = JOptionPane.showInputDialog(null, "input string");

                if (s == null)
                    return;

                if (s.length() == 0)
                    throw new IllegalArgumentException("empty string");

                StringTokenizer tok = new StringTokenizer(s, " ,;\t.");

                targetSemester = Integer.parseInt(tok.nextToken());
                targetSubjects = new TreeSet<>();
                while (tok.hasMoreTokens()) {
                    targetSubjects.add(tok.nextToken().toLowerCase());
                }

                findNotPassed(true);
                view.label3.setText("Criterion: " + s);
                return;

            }
            catch (IllegalArgumentException e) {
                JOptionPane.showMessageDialog(null, e, "Exception", JOptionPane.ERROR_MESSAGE);

            }
        }

    }

    void findNotPassed(boolean type)
    {
        view.resultList.setListData(new Vector<SessionEntry>());

        if (type) {
            if (!model.allSemesters().contains(targetSemester)) {
                JOptionPane.showMessageDialog(null, "No such semester", "Message", JOptionPane.PLAIN_MESSAGE);
                return;
            }

            if (!model.allSubjects().containsAll(targetSubjects)) {
                JOptionPane.showMessageDialog(null, "No such subject", "Message", JOptionPane.PLAIN_MESSAGE);
                return;
            }
        }


        TreeMap< Student, ArrayList<SessionEntry> > entries = new TreeMap<>();

        ListIterator<SessionEntry> it = model.listIterator();
        while (it.hasNext())
        {
            SessionEntry temp = it.next();
            if (temp.semester == targetSemester && targetSubjects.contains(temp.subject.toLowerCase()) && temp.mark < 4)
            {
                if (entries.containsKey(new Student(temp.surname, temp.recordBookNumber))) {
                    entries.get(new Student(temp.surname, temp.recordBookNumber)).add(temp);
                }
                else {
                    ArrayList<SessionEntry> kek = new ArrayList<>();
                    kek.add(temp);
                    entries.put(new Student(temp.surname, temp.recordBookNumber), kek);
                }
            }
        }

        Vector<SessionEntry> res = new Vector<>();
        Vector<ArrayList<SessionEntry>> ans = new Vector<>(entries.values());

        ListIterator<ArrayList<SessionEntry>> iit = ans.listIterator();
        while (iit.hasNext())
        {
            ArrayList<SessionEntry> temp = iit.next();
            if (temp.size() == targetSubjects.size()) {
                res.addAll(temp);
            }
        }

        if (res.isEmpty() && type) {
            JOptionPane.showMessageDialog(null, "No such students", "Message", JOptionPane.PLAIN_MESSAGE);
            return;
        }

        res.sort((o1, o2) -> {
            if (!o1.subject.equals(o2.subject))
                return o1.subject.compareTo(o2.subject);
            return o1.surname.compareTo(o2.surname);
        });
        view.resultList.setListData(res);
    }

    public void clear() {
        model.clear();
        targetSubjects = new TreeSet<>();
        targetSemester = 0;
        view.show = false;
        view.label3.setText("");
        view.resultList.setListData(new Vector());
    }


}
