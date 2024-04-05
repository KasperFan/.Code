package test;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.MenuButton;
import javafx.scene.control.MenuItem;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Test extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        VBox vBox = new VBox();
        MenuItem menuItem1 = new MenuItem("Option 1");
        MenuItem menuItem2 = new MenuItem("Option 2");
        MenuItem menuItem3 = new MenuItem("Option 3");

        MenuButton menuButton =
                new MenuButton("Options",
                        null,
                        menuItem1,
                        menuItem2,
                        menuItem3);
        vBox.getChildren().add(menuButton);
        Scene scene = new Scene(vBox, 200, 123.6);
        primaryStage.setScene(scene);
        primaryStage.show();

        menuItem1.setOnAction(e -> {
            menuButton.setText(menuItem1.getText());
        });

        menuItem2.setOnAction(e -> {
            menuButton.setText(menuItem2.getText());
        });

        menuItem3.setOnAction(e -> {
            menuButton.setText(menuItem3.getText());
        });

    }
}
