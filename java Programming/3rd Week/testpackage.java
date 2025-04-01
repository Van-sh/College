import test.foundation;

public class testpackage {
   public static void main(String[] args) {
      foundation obj = new foundation();
      // System.out.println("var4 (private) = " + obj.var1); // Not accessible (private)
      // System.out.println("var4 (default) = " + obj.var2); // Not accessible (default, different package)
      // System.out.println("var4 (protected) = " + obj.var3); // Not accessible (protected, different package without inheritance)
      System.out.println("var4 (public) = " + obj.var4); // Accessible

      obj.display();
   }
}
