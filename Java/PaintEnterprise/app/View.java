package app;

import javafx.geometry.Insets;
import javafx.scene.Cursor;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.util.ArrayList;
import java.util.List;

import javafx.geometry.Pos;

public class View {

    ToggleButton segmentButton, rayButton, lineButton, rectButton, circleButton, rotateButton;
    ToggleButton[] toolsArr;
    ColorPicker cpLine, cpFill;
    Button clear;

    List<Canvas> mainCanvas;
    List<GraphicsContext> mainGC;
    Canvas auxCanvas;
    GraphicsContext auxGC;

    Stage primaryStage;
    BorderPane pane;
    Scene scene;
    StackPane stack;

    ListView<String> listView;

    public void init(Stage primaryStage) {

        // figure buttons
        this.segmentButton = new ToggleButton("Segment");
        this.rayButton = new ToggleButton("Ray");
        this.lineButton = new ToggleButton("Line");
        this.rectButton = new ToggleButton("Rectangle");
        this.circleButton = new ToggleButton("Circle");

        this.toolsArr = new ToggleButton[] {this.segmentButton, this.rayButton, this.lineButton, this.rectButton, this.circleButton};

        ToggleGroup tools = new ToggleGroup();

        for (ToggleButton tool : toolsArr) {
            tool.setMinWidth(90);
            tool.setToggleGroup(tools);
            tool.setCursor(Cursor.HAND);
            tool.setStyle("-fx-background-color: #A9A9A9;");

            tool.selectedProperty().addListener((observable, oldValue, newValue) -> {
                if (newValue) {
                    tool.setStyle("-fx-background-color: #808080; -fx-text-fill: white");
                } else {
                    tool.setStyle("-fx-background-color: A9A9A9;");
                }
            });
        }

        this.cpLine = new ColorPicker(Color.BLACK);
        this.cpLine.setStyle("-fx-background-color: #A9A9A9;");
        this.cpFill = new ColorPicker(Color.TRANSPARENT);
        this.cpFill.setStyle("-fx-background-color: #A9A9A9;");

        Label line_color = new Label("Line color");
        line_color.setPrefHeight(25);
        Label fill_color = new Label("Fill color");
        fill_color.setPrefHeight(25);

        this.clear = new Button("Clear");
        this.clear.setMinWidth(90);
        this.clear.setCursor(Cursor.HAND);
        this.clear.setStyle("-fx-background-color: #A9A9A9;");

        HBox btns = new HBox(10);
        btns.getChildren().addAll(this.segmentButton, this.rayButton, this.lineButton, this.rectButton, this.circleButton,
                line_color, cpLine, fill_color, this.cpFill, this.clear);
        btns.setPadding(new Insets(5));
        btns.setStyle("-fx-background-color: gainsboro");
        btns.setPrefWidth(100);


        // layers

        this.listView = new ListView<>();

        VBox box = new VBox(listView);
        box.setAlignment(Pos.CENTER);
        listView.setPrefWidth(200);
        listView.setPrefHeight(800);
        box.setStyle("-fx-background-color: gainsboro;");
        listView.setStyle("-fx-background-color: gainsboro; -fx-selection-bar: silver; -fx-selection-bar-non-focused: silver; -fx-background-insets: 0 ;");


        // canvas

        mainCanvas = new ArrayList<>();
        mainGC = new ArrayList<>();

        this.auxCanvas = new Canvas(1000, 800);
        this.auxGC = auxCanvas.getGraphicsContext2D();
        this.auxGC.setLineWidth(2);


        // stage & scene

        this.pane = new BorderPane();
        this.pane.setRight(box);
        this.pane.setTop(btns);
        this.stack = new StackPane(auxCanvas);
        this.stack.setStyle("-fx-background-color: white;");
        this.pane.setCenter(this.stack);
        this.scene = new Scene(this.pane, 1200, 800, Color.WHITE);

        this.primaryStage = primaryStage;
        this.primaryStage.setTitle("PaintEnterprise");
        this.primaryStage.setScene(this.scene);
        this.primaryStage.getIcons().add(new Image("img/logo.png"));
        this.primaryStage.setFullScreen(false);
        this.primaryStage.setResizable(false);
        this.primaryStage.show();
    }

}
