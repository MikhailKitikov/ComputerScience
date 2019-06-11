package lab13_package;

import java.util.*;

class SessionDatabase extends Vector<SessionEntry>
{
    transient MainFrame view;
    transient Controller controller;

    @Override
    public void clear()
    {
        super.clear();
        view.repaint();
    }

    Vector<Integer> allSemesters()
    {
        TreeSet<Integer> unique = new TreeSet<>();
        ListIterator<SessionEntry> it = this.listIterator();
        while (it.hasNext())
        {
            unique.add(it.next().semester);
        }
        return new Vector<>(unique);
    }

    Vector<String> allSubjects()
    {
        TreeSet<String> unique = new TreeSet<>();
        ListIterator<SessionEntry> it = this.listIterator();
        while (it.hasNext())
        {
            unique.add(it.next().subject.toLowerCase());
        }
        return new Vector<>(unique);
    }

}
