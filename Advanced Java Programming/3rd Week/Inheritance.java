class Animal {
   void eat() {
      System.out.println("Animal eats food");
   }
}

class Dog extends Animal {
   void bark() {
      System.out.println("Dog barks");
   }
}

class Puppy extends Dog {
   void weep() {
      System.out.println("Puppy weeps");
   }
}

class Cat extends Animal {
   void meow() {
      System.out.println("Cat meows");
   }
}

interface Flyable {
   void fly();
}

interface Swimmable {
   void swim();
}

class Bird implements Flyable, Swimmable {
   public void fly() {
      System.out.println("Bird flies");
   }

   public void swim() {
      System.out.println("Bird swims");
   }
}

public class Inheritance {
   public static void main(String[] args) {
      SingleInheritance();
      MultilevelInheritance();
      HierarchicalInheritance();
      MultipleInheritance();
   }

   private static void SingleInheritance() {
      System.out.println("Single Inheritance");
      Dog d = new Dog();
      d.eat();
      d.bark();
      System.out.println();
   }

   private static void MultilevelInheritance() {
      System.out.println("Multilevel Inheritance");
      Puppy p = new Puppy();
      p.eat();
      p.bark();
      p.weep();
      System.out.println();
   }

   private static void HierarchicalInheritance() {
      System.out.println("Hierarchical Inheritance");
      Dog d = new Dog();
      Cat c = new Cat();
      d.eat();
      d.bark();
      c.eat();
      c.meow();
      System.out.println();
   }

   private static void MultipleInheritance() {
      System.out.println("Multiple Inheritance");
      Bird b = new Bird();
      b.fly();
      b.swim();
      System.out.println();
   }
}
