public class fruits {
   public static void main(String[] args) {
      Fruit apple = new Apple();
      Fruit orange = new Orange();

      apple.eat();
      orange.eat();
   }
}

class Fruit {
   String name, taste;

   void eat() {
      System.out.println("Eating " + name + " which tastes " + taste);
   }
}

class Apple extends Fruit {
   Apple() {
      name = "Apple";
      taste = "Sweet";
   }
}

class Orange extends Fruit {
   Orange() {
      name = "Orange";
      taste = "Sour";
   }
}
