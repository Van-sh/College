import java.io.Serializable;

public class TestBean {
   public static void main(String args[]) {
      StudentBean s = new StudentBean();
      s.setId(49);
      s.setName("Vansh");
      System.out.println("Student ID: " + s.getId());
      System.out.println("Student Name: " + s.getName());
   }
}

class StudentBean implements Serializable {
   private int id;
   private String name;

   public void setId(int id) {
      this.id = id;
   }

   public int getId() {
      return id;
   }

   public void setName(String name) {
      this.name = name;
   }

   public String getName() {
      return name;
   }
}
