import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Stack;

public class calculator extends JFrame implements ActionListener {
   private JTextField display;
   private Stack<Double> operands;
   private Stack<String> operators;
   private String currentExpression = "";

   public calculator() {
      operands = new Stack<>();
      operators = new Stack<>();
      display = new JTextField();
      display.setEditable(false);
      display.setFont(new Font("Arial", Font.PLAIN, 30));
      display.setHorizontalAlignment(SwingConstants.RIGHT);
      add(display, BorderLayout.NORTH);

      JPanel panel = new JPanel();
      panel.setLayout(new GridLayout(6, 4));
      Font buttonFont = new Font("Arial", Font.PLAIN, 15);
      String[] buttons = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", ".", "=", "+", "C", "sin", "cos", "tan", "log", "sqrt", "pi"};
      for (String text : buttons) {
         JButton button = new JButton(text);
         button.setFont(buttonFont);
         button.addActionListener(this);
         panel.add(button);
      }
      add(panel, BorderLayout.CENTER);
      setTitle("calculator");
      setSize(400, 600);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setVisible(true);
   }

   @Override
   public void actionPerformed(ActionEvent e) {
      String command = e.getActionCommand();
      if (command.equals("C")) {
         display.setText("");
         operands.clear();
         operators.clear();
         currentExpression = ""; 
      } else if (command.equals("=")) {
         compute();
      } else {
         currentExpression += command; 
         display.setText(currentExpression); 
      }
   }

   private void compute() {
      String expr = currentExpression; 
      String[] tokens = expr.split("(?<=\\d)(?=\\D)|(?<=\\D)(?=\\d)");

      Stack<Double> operands = new Stack<>();
      Stack<String> operators = new Stack<>();

      for (String token : tokens) {
         if (token.matches("[0-9.]+")) { 
            operands.push(Double.parseDouble(token));
         } else if (token.matches("[\\+\\-\\*/]")) { 
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(token)) {
               performOperation(operators.pop(), operands);
            }
            operators.push(token);
         } else if (token.equals("sin") || token.equals("cos") || token.equals("tan") || token.equals("log")
               || token.equals("sqrt") || token.equals("pi")) {
            double operand = operands.pop();
            double result = 0;
            switch (token) {
               case "sin":
                  result = Math.sin(Math.toRadians(operand));
                  break;
               case "cos":
                  result = Math.cos(Math.toRadians(operand));
                  break;
               case "tan":
                  result = Math.tan(Math.toRadians(operand));
                  break;
               case "log":
                  result = Math.log(operand);
                  break;
               case "sqrt":
                  result = Math.sqrt(operand);
                  break;
               case "pi":
                  result = Math.PI;
                  break;
            }
            operands.push(result);
         }
      }

      while (!operators.isEmpty()) {
         performOperation(operators.pop(), operands);
      }

      double result = operands.pop();
      display.setText(expr + " = " + result); 
   }

   private void performOperation(String operator, Stack<Double> operands) {
      double b = operands.pop();
      double a = operands.pop();
      double result = 0;

      switch (operator) {
         case "+":
            result = a + b;
            break;
         case "-":
            result = a - b;
            break;
         case "*":
            result = a * b;
            break;
         case "/":
            result = a / b;
            break;
      }

      operands.push(result);
   }

   private int precedence(String operator) {
      if (operator.equals("+") || operator.equals("-")) {
         return 1;
      } else if (operator.equals("*") || operator.equals("/")) {
         return 2;
      }
      return 0;
   }

   public static void main(String[] args) {
      new calculator();
   }
}
