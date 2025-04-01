import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.awt.font.TextAttribute;
import java.util.*;

public class texteditor extends JFrame {
   private JTextArea textArea;
   private JScrollPane scrollPane;
   private JMenuBar menuBar;
   private JMenu fileMenu, formatMenu;
   private JMenuItem newFile, openFile, saveFile, exit;
   private JMenuItem bold, italic, underline, fontSize;

   public texteditor() {
      setTitle("Text Editor");
      setSize(800, 600);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      textArea = new JTextArea();
      textArea.setFont(new Font("Arial", Font.PLAIN, 14));
      scrollPane = new JScrollPane(textArea);
      add(scrollPane, BorderLayout.CENTER);

      menuBar = new JMenuBar();
      fileMenu = new JMenu("File");
      newFile = new JMenuItem("New");
      openFile = new JMenuItem("Open");
      saveFile = new JMenuItem("Save");
      exit = new JMenuItem("Exit");

      newFile.addActionListener(e -> newFile());
      openFile.addActionListener(e -> openFile());
      saveFile.addActionListener(e -> saveFile());
      exit.addActionListener(e -> System.exit(0));

      fileMenu.add(newFile);
      fileMenu.add(openFile);
      fileMenu.add(saveFile);
      fileMenu.addSeparator();
      fileMenu.add(exit);

      formatMenu = new JMenu("Format");
      bold = new JMenuItem("Bold");
      italic = new JMenuItem("Italic");
      underline = new JMenuItem("Underline");
      fontSize = new JMenuItem("Font Size");

      bold.addActionListener(e -> toggleBold());
      italic.addActionListener(e -> toggleItalic());
      underline.addActionListener(e -> toggleUnderline());
      fontSize.addActionListener(e -> changeFontSize());

      formatMenu.add(bold);
      formatMenu.add(italic);
      formatMenu.add(underline);
      formatMenu.add(fontSize);

      menuBar.add(fileMenu);
      menuBar.add(formatMenu);
      setJMenuBar(menuBar);
   }

   private void newFile() {
      textArea.setText("");
   }

   private void openFile() {
      JFileChooser fileChooser = new JFileChooser();
      int result = fileChooser.showOpenDialog(this);
      if (result == JFileChooser.APPROVE_OPTION) {
         File file = fileChooser.getSelectedFile();
         try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            textArea.read(reader, null);
         } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Error opening file", "Error", JOptionPane.ERROR_MESSAGE);
         }
      }
   }

   private void saveFile() {
      JFileChooser fileChooser = new JFileChooser();
      int result = fileChooser.showSaveDialog(this);
      if (result == JFileChooser.APPROVE_OPTION) {
         File file = fileChooser.getSelectedFile();
         try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            textArea.write(writer);
         } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Error saving file", "Error", JOptionPane.ERROR_MESSAGE);
         }
      }
   }

   private void toggleBold() {
      Font currentFont = textArea.getFont();
      if (currentFont.getStyle() == Font.BOLD) {
         textArea.setFont(currentFont.deriveFont(Font.PLAIN));
      } else {
         textArea.setFont(currentFont.deriveFont(Font.BOLD));
      }
   }

   private void toggleItalic() {
      Font currentFont = textArea.getFont();
      if (currentFont.getStyle() == Font.ITALIC) {
         textArea.setFont(currentFont.deriveFont(Font.PLAIN));
      } else {
         textArea.setFont(currentFont.deriveFont(Font.ITALIC));
      }
   }

   private void toggleUnderline() {
      Map<TextAttribute, Object> attributes = new HashMap<>(textArea.getFont().getAttributes());
      if (attributes.get(TextAttribute.UNDERLINE) == TextAttribute.UNDERLINE_ON) {
         attributes.put(TextAttribute.UNDERLINE, -1);
      } else {
         attributes.put(TextAttribute.UNDERLINE, TextAttribute.UNDERLINE_ON);
      }
      textArea.setFont(new Font(attributes));
   }

   private void changeFontSize() {
      String newSizeStr = JOptionPane.showInputDialog(this, "Enter font size:", textArea.getFont().getSize());
      try {
         int newSize = Integer.parseInt(newSizeStr);
         if (newSize > 0) {
            textArea.setFont(new Font(textArea.getFont().getName(), textArea.getFont().getStyle(), newSize));
         }
      } catch (NumberFormatException e) {
         JOptionPane.showMessageDialog(this, "Invalid font size", "Error", JOptionPane.ERROR_MESSAGE);
      }
   }

   public static void main(String[] args) {
      SwingUtilities.invokeLater(() -> {
         new texteditor().setVisible(true);
      });
   }
}
