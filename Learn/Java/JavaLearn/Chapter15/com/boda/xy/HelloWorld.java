package com.boda.xy;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class HelloWorld extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        var label = new Label("第一个JavaFX程序");
        var rootPane = new StackPane();
        rootPane.getChildren().add(label);

        var scene = new Scene(rootPane, 200, 60);
        stage.setScene(scene);
        stage.setTitle("JavaFX程序");
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
