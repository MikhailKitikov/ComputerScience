package app;

import javafx.application.Application;
import javafx.stage.Stage;


public class App extends Application {

    @Override
    public void start(Stage primaryStage) {

        View view = new View();
        view.init(primaryStage);

        Model model = new Model();

        Controller controller = new Controller();
        controller.init(view, model);
    }

    public static void main(String[] args) {
        launch(args);
    }
}