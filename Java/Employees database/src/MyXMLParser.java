import org.w3c.dom.*;
import org.xml.sax.*;

import javax.xml.parsers.*;
import java.io.File;
import java.io.IOException;
import java.util.Vector;

class MyXMLParser {

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

    void readData(File file, Vector<Person> people) throws IllegalArgumentException, ParserConfigurationException, SAXException, IOException, MyException {

        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        dbf.setValidating(true);

        DocumentBuilder db = dbf.newDocumentBuilder();
        db.setErrorHandler(new MyErrorHandler());

        Document doc = db.parse(file);
        Element root = doc.getDocumentElement();
        root.normalize();

        people.clear();

        NodeList elements = root.getElementsByTagName("employee");

        for (int i = 0; i < elements.getLength(); ++i) {

            Element element = (Element) elements.item(i);

            if (element.getNodeType() == Node.ELEMENT_NODE) {

                String surname = element.getElementsByTagName("surname").item(0).getTextContent();
                Employee.Position position = Employee.Position.valueOf(element.getElementsByTagName("position").item(0).getTextContent());
                int salary = Integer.parseInt(element.getElementsByTagName("salary").item(0).getTextContent());
                people.add(new Employee(surname, position, salary));
            }
        }

    }
}
