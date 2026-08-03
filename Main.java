class Student {
    int rollNo;
    String name;

    void display() {
        System.out.println("Roll: " + rollNo + ", Name: " + name);
    }
}

public class Main {
    public static void main(String[] args) {
        // Object creation
        Student s1 = new Student();
        s1.rollNo = 1;
        s1.name = "Alice";
        s1.display();

        Student s2 = new Student();
        s2.rollNo = 2;
        s2.name = "Bob";
        s2.display();
    }
}
