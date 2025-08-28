// Import necessary packages for GUI components and event handling
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// Main calculator class implementing ActionListener for button events
public class Calculator implements ActionListener{

    // GUI components declaration
    JFrame frame;                   // Main window frame
    JTextField textfield;            // Display for calculator input/output
    JTextArea htextfield;
    JButton[] numberButtons = new JButton[10];  // Array for digit buttons 0-9
    JButton[] functionButtons = new JButton[8]; // Array for function buttons
    // Individual operation buttons
    JButton addButton, subButton, mulButton, divButton;
    JButton decButton, equButton, delButton, clrButton;
    JPanel panel;                   // Panel to hold buttons in grid layout

    // Font for calculator display and buttons
    Font myFont = new Font("Helvetica", Font.BOLD, 30);

    // Variables for calculator operations
    double num1 = 0, num2 = 0, result = 0;  // Operands and result storage
    String operator;                        // Stores current operation

    // Constructor to set up the calculator GUI
    Calculator(){
        // Create and configure main frame
        frame = new JFrame("Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close on exit
        frame.setSize(350, 532);            // Set window size
        frame.setLayout(null);              // Use absolute positioning
        frame.setResizable(false);         // Prevent window resizing

        // Create and configure text field for display
        textfield = new JTextField();
        textfield.setBounds(18, 18, 300, 65);  // Position and size
        textfield.setFont(myFont);             // Set font
        textfield.setEditable(false);         // Prevent direct text input
        textfield.setHorizontalAlignment(JTextField.RIGHT); // Right-align text

        // Initialize operation buttons with their symbols
        addButton = new JButton("+");
        subButton = new JButton("-");
        mulButton = new JButton("×");
        divButton = new JButton("÷");
        decButton = new JButton(".");
        equButton = new JButton("=");
        delButton = new JButton("D");      // Delete button
        clrButton = new JButton("C");      // Clear button

        // Assign buttons to functionButtons array
        functionButtons[0] = addButton;
        functionButtons[1] = subButton;
        functionButtons[2] = mulButton;
        functionButtons[3] = divButton;
        functionButtons[4] = decButton;
        functionButtons[5] = equButton;
        functionButtons[6] = delButton;
        functionButtons[7] = clrButton;

        // Configure function buttons
        for(int i = 0; i < 8; i++) {
            functionButtons[i].addActionListener(this);  // Add event listener
            functionButtons[i].setFont(myFont);         // Set font
            functionButtons[i].setFocusable(false);   // Prevent focus border
            
            // Styling for transparent buttons
            functionButtons[i].setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
            functionButtons[i].setBorderPainted(false);
            functionButtons[i].setContentAreaFilled(false);
        }

        // Configure number buttons (0-9)
        for(int i = 0; i < 10; i++) {
            numberButtons[i] = new JButton(String.valueOf(i)); // Create button with digit
            numberButtons[i].addActionListener(this);         // Add event listener
            numberButtons[i].setFont(myFont);                // Set font
            numberButtons[i].setFocusable(false);            // Prevent focus border
            
            // Styling for transparent buttons
            numberButtons[i].setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
            numberButtons[i].setBorderPainted(false);
            numberButtons[i].setContentAreaFilled(false);
        }

        // Position delete and clear buttons
        delButton.setBounds(172, 94, 68, 50);
        clrButton.setBounds(248, 94, 68, 50);

        // Create panel for number and operation buttons
        panel = new JPanel();
        panel.setBounds(18, 150, 300, 320);  // Position and size
        panel.setLayout(new GridLayout(4, 4, 5, 5)); // 4x4 grid with 5px gaps


        // Add buttons to panel in calculator layout
        panel.add(numberButtons[7]);
        panel.add(numberButtons[8]);
        panel.add(numberButtons[9]);
        panel.add(mulButton);
        panel.add(numberButtons[4]);
        panel.add(numberButtons[5]);
        panel.add(numberButtons[6]);
        panel.add(addButton);
        panel.add(numberButtons[1]);
        panel.add(numberButtons[2]);
        panel.add(numberButtons[3]);
        panel.add(subButton);
        panel.add(decButton);
        panel.add(numberButtons[0]);
        panel.add(equButton);
        panel.add(divButton);

        // Add components to frame
        frame.add(panel);
        frame.add(delButton);
        frame.add(clrButton);
        frame.add(textfield);
        frame.setVisible(true);  // Make frame visible
    }

    // Main method to create calculator instance
    public static void main(String[] args) {
        Calculator calc = new Calculator();
    }

    // Event handler for button clicks
    @Override
    public void actionPerformed(ActionEvent e) {
        // Handle number button presses
        for(int i = 0; i < 10; i++) {
            if(e.getSource() == numberButtons[i]) {
                // Append pressed digit to display
                textfield.setText(textfield.getText().concat(String.valueOf(i)));
            }
        }
        
        // Handle decimal point button
        if(e.getSource() == decButton) {
            String temp = textfield.getText();
            if (!temp.contains(".")) {  // Prevent multiple decimals
                textfield.setText(temp + ".");
            }
        }
        
        // Handle operation buttons (store first operand and operation)
        if(e.getSource() == addButton) {
            num1 = Double.parseDouble(textfield.getText());
            operator = "+";
            textfield.setText("");  // Clear for second operand
        }
        if(e.getSource() == subButton) {
            num1 = Double.parseDouble(textfield.getText());
            operator = "-";
            textfield.setText("");
        }
        if(e.getSource() == mulButton) {
            num1 = Double.parseDouble(textfield.getText());
            operator = "×";
            textfield.setText("");
        }
        if(e.getSource() == divButton) {
            num1 = Double.parseDouble(textfield.getText());
            operator = "÷";
            textfield.setText("");
        }
        
        // Handle equals button (perform calculation)
        if(e.getSource() == equButton) {
            num2 = Double.parseDouble(textfield.getText());  // Get second operand
            
            // Perform operation based on stored operator
            switch(operator) {
                case "+":
                    result = num1 + num2;
                    break;
                case "-":
                    result = num1 - num2;
                    break;
                case "×":
                    result = num1 * num2;
                    break;
                case "÷":
                    result = num1 / num2;
                    break;
            }
            textfield.setText(String.valueOf(result));  // Display result
            num1 = result;  // Store result for chained operations
        }
        
        // Handle clear button (reset display)
        if (e.getSource() == clrButton) {
            textfield.setText("");
        }
        
        // Handle delete button (backspace)
        if (e.getSource() == delButton) {
            String string = textfield.getText();
            if (!string.isEmpty()) {  // Only if there's text to delete
                StringBuilder sb = new StringBuilder(string);
                sb.deleteCharAt(sb.length() - 1);  // Remove last character
                textfield.setText(sb.toString());
            }
        }
    }
}