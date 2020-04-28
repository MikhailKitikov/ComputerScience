package lab13_package;

import org.w3c.dom.*;
import org.xml.sax.*;

import javax.xml.parsers.*;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;
import java.io.IOException;

class MyXMLParser
{
    class MyErrorHandler implements ErrorHandler {
        @Override
        public void warning(SAXParseException exception) throws SAXException {
            throw new SAXException();
        }

        @Override
        public void error(SAXParseException exception) throws SAXException {
            throw new SAXException();
        }

        @Override
        public void fatalError(SAXParseException exception) throws SAXException {
            throw new SAXException();
        }
    }

    public void readData(File file, SessionDatabase model) throws IOException, ParserConfigurationException, SAXException
    {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        dbf.setValidating(true);

        DocumentBuilder db = dbf.newDocumentBuilder();
        db.setErrorHandler(new MyErrorHandler());

        Document doc = db.parse(file);
        doc.getDocumentElement().normalize();

        model.clear();
        NodeList entryList = doc.getElementsByTagName("SessionEntry");

        for (int i = 0; i < entryList.getLength(); ++i)
        {
            Element element = (Element)entryList.item(i);

            if (element.getNodeType() == Node.ELEMENT_NODE)
            {
                int number = Integer.parseInt(element.getElementsByTagName("recordBookNumber").item(0).getTextContent());
                String surname = element.getElementsByTagName("surname").item(0).getTextContent();
                int sem = Integer.parseInt(element.getElementsByTagName("semester").item(0).getTextContent());
                String subject = element.getElementsByTagName("subject").item(0).getTextContent();
                int mark = Integer.parseInt(element.getElementsByTagName("mark").item(0).getTextContent());

                model.add(new SessionEntry(number, surname, sem, subject, mark));
            }
        }
    }

    public void writeData(File file, SessionDatabase model) throws ParserConfigurationException, TransformerException
    {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.newDocument();

        Element root = doc.createElement("SessionDatabase");
        doc.appendChild(root);

        for (SessionEntry sessionEntry : model)
        {
            Element entry = doc.createElement("SessionEntry");
            root.appendChild(entry);

            Element number = doc.createElement("recordBookNumber");
            number.appendChild(doc.createTextNode(Integer.toString(sessionEntry.recordBookNumber)));
            entry.appendChild(number);

            Element surname = doc.createElement("surname");
            surname.appendChild(doc.createTextNode(sessionEntry.surname));
            entry.appendChild(surname);

            Element semester = doc.createElement("semester");
            semester.appendChild(doc.createTextNode(Integer.toString(sessionEntry.semester)));
            entry.appendChild(semester);

            Element subject = doc.createElement("subject");
            subject.appendChild(doc.createTextNode(sessionEntry.subject));
            entry.appendChild(subject);

            Element mark = doc.createElement("mark");
            mark.appendChild(doc.createTextNode(Integer.toString(sessionEntry.mark)));
            entry.appendChild(mark);
        }

        TransformerFactory tf = TransformerFactory.newInstance();
        Transformer transformer = tf.newTransformer();
        DOMSource domSource = new DOMSource(doc);
        StreamResult streamResult = new StreamResult(file);
        transformer.transform(domSource, streamResult);
    }
}
