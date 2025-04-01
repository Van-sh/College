public class animals {
   public static void main(String[] args) {
      Animal a = new Animal();
      a.eat();
      a.sleep();

      Bird b = new Bird();
      b.eat();
      b.sleep();
      b.fly();
   }
}

class Animal {
   void eat() {
      System.out.println("Animal is eating");
   }

   void sleep() {
      System.out.println("Animal is sleeping");
   }
}

class Bird extends Animal {
   void eat() {
      System.out.println("Bird is eating");
   }

   void sleep() {
      System.out.println("Bird is sleeping");
   }

   void fly() {
      System.out.println("Bird is flying");
   }
}
