class Animal {
    void makeSound() {
        System.out.println("Animal makes a sound");
        try {
            // Code that may throw an exception
            int result = 10 / 0; // This will throw an ArithmeticException
        } catch (ArithmeticException e) {
            // Print error message with line number, class name, and method name
            System.err.println("Error occurred:");
            System.err.println("Class: " + e.getStackTrace()[0].getClassName());
            System.err.println("Method: " + e.getStackTrace()[0].getMethodName());
            System.err.println("Line: " + e.getStackTrace()[0].getLineNumber());
            e.printStackTrace(); // Print the full stack trace for additional information
        }
    }
}

class Dog extends Animal {
    @Override
    void makeSound() {
        System.out.println("Dog barks");
    }

    void fetch() {
        System.out.println("Dog fetches a ball");
    }

    void hello() {
        System.out.println("Hello in DOG");
    }
}

class Cat extends Animal {
    @Override
    void makeSound() {
        System.out.println("Cat meows");
        try {
            // Code that may throw an exception
            int result = 10 / 0; // This will throw an ArithmeticException
        } catch (ArithmeticException e) {
            // Print error message with line number, class name, and method name
            System.err.println("Error occurred:");
            System.err.println("Class: " + e.getStackTrace()[0].getClassName());
            System.err.println("Method: " + e.getStackTrace()[0].getMethodName());
            System.err.println("Line: " + e.getStackTrace()[0].getLineNumber());
            e.printStackTrace(); // Print the full stack trace for additional information
        }
    }

    void scratch() {
        System.out.println("Cat scratches");
    }
}

public class Main {
    public static void main(String[] args) {
        // Upcasting: Creating objects of subclass and assigning to superclass reference
        Animal animal1 = new Dog(); // Upcast Dog to Animal
        Animal animal2 = new Cat(); // Upcast Cat to Animal
        // animal1.hello();
        animal1.makeSound();
        // Downcasting: Casting from superclass to subclass
        Dog dog = (Dog) animal1; // Downcast Animal to Dog
        Cat cat = (Cat) animal2; // Downcast Animal to Cat

        // Calling methods after downcastin
        dog.makeSound(); // Calls Dog's makeSound
        dog.fetch(); // Calls Dog's fetch
        dog.hello();
        cat.makeSound(); // Calls Cat's makeSound
        cat.scratch(); // Calls Cat's scratch

        // Attempting invalid downcasting
        // Dog invalidDog = (Dog) animal2; // This will throw a ClassCastException
    }
}
