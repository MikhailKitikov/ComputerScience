package lab13_package;

import java.io.Serializable;

class SessionEntry implements Serializable
{
    int recordBookNumber;
    String surname;
    int semester;
    String subject;
    int mark;

    public SessionEntry(int recordBookNumber, String surname, int semester,
                        String subject, int mark) throws IllegalArgumentException
    {
        if (recordBookNumber < 0 || surname == null || surname.length() == 0 || subject == null ||
            subject.length() == 0 || mark < 0 || mark > 10)
        {
            throw new IllegalArgumentException();
        }
        this.recordBookNumber = recordBookNumber;
        this.surname = surname;
        this.semester = semester;
        this.subject = subject;
        this.mark = mark;
    }

    public String toString() {
        return recordBookNumber + " " +
                surname + " " +
                semester + " " +
                subject + " " +
                mark;
    }
}
