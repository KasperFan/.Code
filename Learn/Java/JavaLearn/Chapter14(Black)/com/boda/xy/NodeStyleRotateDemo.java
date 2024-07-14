package com.boda.xy;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class NodeStyleRotateDemo extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        // Create a scene and place a button in the scene
        StackPane pane = new StackPane();
        Button btOk = new Button("OK");
        btOk.setStyle("-fx-border-color: blue");
        pane.getChildren().add(btOk);

        pane.setRotate(45);
        pane.setStyle(
                "-fx-border-color: red; -fx-background-color: lightgray; visibility: ");

        Scene scene = new Scene(pane, 400, 250);
        primaryStage.setTitle("NodeStyleRotateDemo"); // Set the stage title
        primaryStage.setScene(scene); // Place the scene in the stage
        primaryStage.show(); // Display the stage
    }
}
