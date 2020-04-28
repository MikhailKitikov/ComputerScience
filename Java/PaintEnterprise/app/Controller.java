package app;

import geometry.*;
import geometry.Polygon;
import geometry.Rectangle;
import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.ListCell;
import javafx.scene.control.ToggleButton;
import javafx.scene.input.KeyCode;
import javafx.scene.input.MouseEvent;
import java.awt.*;


public class Controller {

    public View view;
    public Model model;

    Segment tempSegment;
    Ray tempRay;
    Line tempLine;
    Rectangle tempRectangle;
    Circle tempCircle;
    Polygon tempPolygon;

    boolean moveMode = false;
    int moveIndex;
    Point moveStart, moveEnd;

    protected void resetMovingState() {
        moveStart = null;
        moveEnd = null;
    }

    public void init(View view, Model model) {

        // model & view
        this.view = view;
        this.model = model;


        // figures
        this.tempSegment = new Segment();
        this.tempRay = new Ray();
        this.tempLine = new Line();
        this.tempRectangle = new Rectangle();
        this.tempCircle = new Circle();
        this.tempPolygon = new Polygon();


        view.clear.setOnMouseClicked(event -> {
            model.clear();
            view.mainCanvas.clear();
            view.mainGC.clear();
            view.stack.getChildren().clear();
            view.stack.getChildren().add(view.auxCanvas);
            resetMovingState();
            moveMode = false;
            moveIndex = 0;
        });


        // view triggers
        this.view.auxCanvas.setOnMousePressed(new MousePressedController());
        this.view.auxCanvas.setOnMouseReleased(new MouseReleasedController());
        this.view.auxCanvas.setOnMouseDragged(new MouseDraggedController());


        // layers list listeners
        view.listView.setItems(model.names);
        view.listView.setCellFactory(param -> new ListCell<>() {
            @Override
            public void updateItem(String name, boolean empty) {
                super.updateItem(name, empty);
                if (empty) {
                    setText(null);
                } else {
                    setText(name);
                }
            }
        });

        view.listView.setOnKeyPressed(keyEvent -> {
            int n = model.size;
            int pos = view.listView.getSelectionModel().getSelectedIndex();
            if (n <= 0 || pos >= n || pos == -1) {
                return;
            }
            if (keyEvent.getCode().equals(KeyCode.DELETE)) {
                model.delFigure(pos);
                view.mainCanvas.remove(pos);
                view.mainGC.remove(pos);
                view.stack.getChildren().remove(pos);
                moveMode = false;
                resetMovingState();
                view.listView.getSelectionModel().clearSelection();
            }
            else if (keyEvent.getCode().equals(KeyCode.ESCAPE)) {
                moveMode = false;
                view.listView.getSelectionModel().clearSelection();
            }
        });

        view.listView.setOnMouseClicked(event -> {
            int n = model.size;
            int pos = view.listView.getSelectionModel().getSelectedIndex();
            if (n <= 0 || pos >= n || pos == -1) {
                return;
            }
            for (ToggleButton tool : view.toolsArr) {
                tool.setSelected(false);
            }
            if (moveMode) {
                resetMovingState();
            }
            moveMode = true;
            moveIndex = pos;
        });


        // button group listener
        for (ToggleButton tool : view.toolsArr) {
            tool.setOnMouseClicked(event -> {
                resetMovingState();
                moveMode = false;
                view.listView.getSelectionModel().clearSelection();
            });
        }
    }


    // subController for mouse pressed event
    public class MousePressedController implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent event) {
            if (moveMode) {
                moveStart = new Point((int)event.getX(), (int)event.getY());
                moveEnd = new Point(moveStart);
                view.auxGC.setStroke((model.getFigure(moveIndex)).borderColor);
                if (model.getFigure(moveIndex) instanceof AbstractFigure2D) {
                    view.auxGC.setFill(((AbstractFigure2D)model.getFigure(moveIndex)).fillColor);
                }
                model.getFigure(moveIndex).draw(view.auxGC);
                view.mainGC.get(moveIndex).clearRect(0, 0,
                        view.mainCanvas.get(moveIndex).getWidth(),
                        view.mainCanvas.get(moveIndex).getHeight());
            }
            else {
                if(view.segmentButton.isSelected()) {
                    tempSegment.setCenter(new Point((int)event.getX(), (int)event.getY()));
                }
                else if(Controller.this.view.rayButton.isSelected()) {
                    tempRay.setCenter(new Point((int)event.getX(), (int)event.getY()));
                }
                else if(Controller.this.view.lineButton.isSelected()) {
                    tempLine.setCenter(new Point((int)event.getX(), (int)event.getY()));
                }
                else if(Controller.this.view.rectButton.isSelected()) {
                    tempRectangle.setStart(new Point((int)event.getX(), (int)event.getY()));
                }
                else if(Controller.this.view.circleButton.isSelected()) {
                    tempCircle.setCenter(new Point((int)event.getX(), (int)event.getY()));
                }
            }
        }
    }


    // subController for mouse dragged event
    public class MouseDraggedController implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent event) {
            if (moveMode) {
                moveStart = moveEnd;
                moveEnd = new Point((int)event.getX(), (int)event.getY());
                view.auxGC.clearRect(0, 0, Controller.this.view.auxCanvas.getWidth(), Controller.this.view.auxCanvas.getHeight());
                int shiftX = moveEnd.x - moveStart.x;
                int shiftY = moveEnd.y - moveStart.y;
                model.getFigure(moveIndex).move(shiftX, shiftY);
                model.getFigure(moveIndex).draw(Controller.this.view.auxGC);
            }
            else {
                if(Controller.this.view.segmentButton.isSelected()) {
                    Controller.this.view.auxGC.setStroke(Controller.this.view.cpLine.getValue());
                    Controller.this.view.auxGC.clearRect(0, 0, Controller.this.view.auxCanvas.getWidth(), Controller.this.view.auxCanvas.getHeight());
                    Controller.this.tempSegment.setSecondPoint(new Point((int)event.getX(), (int)event.getY()));
                    Controller.this.tempSegment.draw(Controller.this.view.auxGC);
                }
                else if(Controller.this.view.rayButton.isSelected()) {
                    Controller.this.view.auxGC.setStroke(Controller.this.view.cpLine.getValue());
                    Controller.this.view.auxGC.clearRect(0, 0, Controller.this.view.auxCanvas.getWidth(), Controller.this.view.auxCanvas.getHeight());
                    Controller.this.tempRay.setSecondPoint(new Point((int)event.getX(), (int)event.getY()));
                    Controller.this.tempRay.draw(Controller.this.view.auxGC);
                }
                else if(Controller.this.view.lineButton.isSelected()) {
                    Controller.this.view.auxGC.setStroke(Controller.this.view.cpLine.getValue());
                    Controller.this.view.auxGC.clearRect(0, 0, Controller.this.view.auxCanvas.getWidth(), Controller.this.view.auxCanvas.getHeight());
                    Controller.this.tempLine.setSecondPoint(new Point((int)event.getX(), (int)event.getY()));
                    Controller.this.tempLine.draw(Controller.this.view.auxGC);
                }
                else if(Controller.this.view.rectButton.isSelected()) {
                    Controller.this.view.auxGC.setStroke(Controller.this.view.cpLine.getValue());
                    Controller.this.view.auxGC.setFill(Controller.this.view.cpFill.getValue());
                    Controller.this.view.auxGC.clearRect(0, 0, Controller.this.view.auxCanvas.getWidth(), Controller.this.view.auxCanvas.getHeight());
                    Controller.this.tempRectangle.setEnd(new Point((int)event.getX(), (int)event.getY()));
                    Controller.this.tempRectangle.draw(Controller.this.view.auxGC);
                }
                else if(Controller.this.view.circleButton.isSelected()) {
                    Controller.this.view.auxGC.setStroke(Controller.this.view.cpLine.getValue());
                    Controller.this.view.auxGC.setFill(Controller.this.view.cpFill.getValue());
                    Controller.this.view.auxGC.clearRect(0, 0, Controller.this.view.auxCanvas.getWidth(), Controller.this.view.auxCanvas.getHeight());
                    Point center = tempCircle.center;
                    Controller.this.tempCircle.radius = Math.sqrt(Math.pow(center.x - event.getX(), 2) + Math.pow(center.y - event.getY(), 2));
                    Controller.this.tempCircle.draw(Controller.this.view.auxGC);
                }
            }
        }
    }


    // subController for mouse released event
    public class MouseReleasedController implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent event) {
            if (moveMode) {
                moveStart = moveEnd;
                moveEnd = new Point((int)event.getX(), (int)event.getY());
                int shiftX = moveEnd.x - moveStart.x;
                int shiftY = moveEnd.y - moveStart.y;
                model.getFigure(moveIndex).move(shiftX, shiftY);
                Controller.this.view.auxGC.clearRect(0, 0,
                        Controller.this.view.auxCanvas.getWidth(),
                        Controller.this.view.auxCanvas.getHeight());
                model.getFigure(moveIndex).draw(view.mainGC.get(moveIndex));
            }
            else {
                if(view.segmentButton.isSelected()) {
                    tempSegment.setSecondPoint(new Point((int)event.getX(), (int)event.getY()));
                    model.addFigure(new Segment(tempSegment));
                    //
                    Canvas newCanvas = new Canvas(1000, 800);
                    view.mainCanvas.add(newCanvas);
                    view.stack.getChildren().add(model.size - 1, newCanvas);
                    GraphicsContext gc = newCanvas.getGraphicsContext2D();
                    gc.setLineWidth(2);
                    gc.setStroke(view.cpLine.getValue());
                    gc.setFill(view.cpFill.getValue());
                    view.mainGC.add(gc);
                    tempSegment.draw(gc);
                    Controller.this.view.auxGC.clearRect(0, 0,
                            Controller.this.view.auxCanvas.getWidth(),
                            Controller.this.view.auxCanvas.getHeight());
                    model.getFigure(model.size - 1).borderColor = view.cpLine.getValue();
                }
                else if(Controller.this.view.rayButton.isSelected()) {
                    Controller.this.tempRay.setSecondPoint(new Point((int)event.getX(), (int)event.getY()));
                    model.addFigure(new Ray(tempRay));
                    //
                    Canvas newCanvas = new Canvas(1000, 800);
                    view.mainCanvas.add(newCanvas);
                    view.stack.getChildren().add(model.size - 1, newCanvas);
                    GraphicsContext gc = newCanvas.getGraphicsContext2D();
                    gc.setLineWidth(2);
                    gc.setStroke(view.cpLine.getValue());
                    gc.setFill(view.cpFill.getValue());
                    view.mainGC.add(gc);
                    tempRay.draw(gc);
                    Controller.this.view.auxGC.clearRect(0, 0,
                            Controller.this.view.auxCanvas.getWidth(),
                            Controller.this.view.auxCanvas.getHeight());
                    model.getFigure(model.size - 1).borderColor = view.cpLine.getValue();
                }
                else if(Controller.this.view.lineButton.isSelected()) {
                    Controller.this.tempLine.setSecondPoint(new Point((int)event.getX(), (int)event.getY()));
                    model.addFigure(new Line(tempLine));
                    //
                    Canvas newCanvas = new Canvas(1000, 800);
                    view.mainCanvas.add(newCanvas);
                    view.stack.getChildren().add(model.size - 1, newCanvas);
                    GraphicsContext gc = newCanvas.getGraphicsContext2D();
                    gc.setLineWidth(2);
                    gc.setStroke(view.cpLine.getValue());
                    gc.setFill(view.cpFill.getValue());
                    view.mainGC.add(gc);
                    tempLine.draw(gc);
                    Controller.this.view.auxGC.clearRect(0, 0,
                            Controller.this.view.auxCanvas.getWidth(),
                            Controller.this.view.auxCanvas.getHeight());
                    model.getFigure(model.size - 1).borderColor = view.cpLine.getValue();
                }
                else if(Controller.this.view.rectButton.isSelected()) {
                    Controller.this.tempRectangle.setEnd(new Point((int)event.getX(), (int)event.getY()));
                    Controller.this.tempRectangle.fillColor = view.cpFill.getValue();
                    model.addFigure(new Rectangle(tempRectangle));
                    //
                    Canvas newCanvas = new Canvas(1000, 800);
                    view.mainCanvas.add(newCanvas);
                    view.stack.getChildren().add(model.size - 1, newCanvas);
                    GraphicsContext gc = newCanvas.getGraphicsContext2D();
                    gc.setLineWidth(2);
                    gc.setStroke(view.cpLine.getValue());
                    gc.setFill(view.cpFill.getValue());
                    view.mainGC.add(gc);
                    tempRectangle.draw(gc);
                    Controller.this.view.auxGC.clearRect(0, 0,
                            Controller.this.view.auxCanvas.getWidth(),
                            Controller.this.view.auxCanvas.getHeight());
                    model.getFigure(model.size - 1).borderColor = view.cpLine.getValue();
                }
                else if(Controller.this.view.circleButton.isSelected()) {
                    Point center = tempCircle.center;
                    Controller.this.tempCircle.radius = Math.sqrt(Math.pow(center.x - event.getX(), 2) + Math.pow(center.y - event.getY(), 2));
                    Controller.this.tempCircle.fillColor = view.cpFill.getValue();
                    model.addFigure(new Circle(tempCircle));
                    //
                    Canvas newCanvas = new Canvas(1000, 800);
                    view.mainCanvas.add(newCanvas);
                    view.stack.getChildren().add(model.size - 1, newCanvas);
                    GraphicsContext gc = newCanvas.getGraphicsContext2D();
                    gc.setLineWidth(2);
                    gc.setStroke(view.cpLine.getValue());
                    gc.setFill(view.cpFill.getValue());
                    view.mainGC.add(gc);
                    tempCircle.draw(gc);
                    Controller.this.view.auxGC.clearRect(0, 0,
                            Controller.this.view.auxCanvas.getWidth(),
                            Controller.this.view.auxCanvas.getHeight());
                    model.getFigure(model.size - 1).borderColor = view.cpLine.getValue();
                }
            }
        }
    }
}
