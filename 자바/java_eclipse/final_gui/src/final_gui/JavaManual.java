package final_gui;

import javax.swing.*;
import java.awt.*;

public class JavaManual extends JPanel {
    public JavaManual() {
        setLayout(new BorderLayout());
        initializeTabs();
    }

    private void initializeTabs() {
        JTabbedPane tabbedPane = new JTabbedPane();

        // 탭 추가
        tabbedPane.addTab("Introduction", createTextPanel("Java is a high-level, class-based, object-oriented programming language that is designed to have as few implementation dependencies as possible."));
        tabbedPane.addTab("Variables", createTextPanel("Variables are containers for storing data values. In Java, there are different types of variables, for example, int, String, boolean, etc."));
        tabbedPane.addTab("Data Types", createTextPanel("Java has a rich set of data types. Primitive data types include byte, short, int, long, float, double, boolean, and char. Non-primitive data types include Strings, Arrays, and Classes."));
        tabbedPane.addTab("Operators", createTextPanel("Operators are used to perform operations on variables and values. Java supports various operators, such as arithmetic operators, relational operators, and logical operators."));
        tabbedPane.addTab("Control Statements", createTextPanel("Control statements are used to control the flow of execution. Common control statements include if-else, switch-case, loops (for, while, do-while)."));
        tabbedPane.addTab("Classes & Objects", createTextPanel("Java is an object-oriented programming language. Everything in Java is associated with classes and objects. A class is a blueprint for objects, and an object is an instance of a class."));
        tabbedPane.addTab("Inheritance", createTextPanel("Inheritance is a mechanism wherein a new class is derived from an existing class. The derived class inherits the properties and methods of the base class."));
        tabbedPane.addTab("Polymorphism", createTextPanel("Polymorphism means 'many forms', and it occurs when we have many classes that are related to each other by inheritance. Polymorphism allows methods to do different things based on the object it is acting upon."));
        tabbedPane.addTab("Abstraction", createTextPanel("Abstraction is a process of hiding the implementation details and showing only functionality to the user. In Java, abstraction is achieved using abstract classes and interfaces."));
        tabbedPane.addTab("Encapsulation", createTextPanel("Encapsulation is the technique of making the fields in a class private and providing access to the fields via public methods. This helps in hiding the implementation details and protecting the data."));

        add(tabbedPane, BorderLayout.CENTER);
    }

    private JPanel createTextPanel(String text) {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        JTextArea textArea = new JTextArea();
        textArea.setText(text);
        textArea.setEditable(false);
        textArea.setFont(new Font("Arial", Font.PLAIN, 16));
        JScrollPane scrollPane = new JScrollPane(textArea);
        panel.add(scrollPane, BorderLayout.CENTER);
        return panel;
    }
}
