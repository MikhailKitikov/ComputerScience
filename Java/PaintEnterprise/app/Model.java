package app;

import geometry.AbstractFigure;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.util.ArrayList;

public class Model {

    ArrayList<AbstractFigure> figures = new ArrayList<>();
    ObservableList<String> names = FXCollections.observableArrayList();
    int size = 0;

    public void addFigure(AbstractFigure fig) {
        figures.add(fig);
        names.add(fig.info());
        ++size;
    }

    public void delFigure(int index) {
        figures.remove(index);
        names.remove(index);
        --size;
    }

    public AbstractFigure getFigure(int index) {
        return figures.get(index);
    }

    public void clear() {
        figures.clear();
        names.clear();
        size = 0;
    }
}
