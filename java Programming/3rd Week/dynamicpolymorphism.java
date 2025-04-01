public class dynamicpolymorphism {
   public static void main(String[] args) {
      AnimalTest a = new Dog();
      a.sound();

      AnimalTest b = new Cat();
      b.sound();
   }
}

interface AnimalTest {
   void sound();
}

class Dog implements AnimalTest {
   @Override
   public void sound() {
      System.out.println("Dog barks");
   }
}

class Cat implements AnimalTest {
   @Override
   public void sound() {
      System.out.println("Cat meows");
   }
}
