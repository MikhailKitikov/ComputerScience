package lab13_package;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class AddItemListener implements ActionListener
{
    AddItemDialog dialog;

    AddItemListener(AddItemDialog dialog)
    {
        this.dialog = dialog;
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        dialog.controller.addItem(dialog);
    }
}
