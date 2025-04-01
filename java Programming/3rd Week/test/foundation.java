package test;

public class foundation {
    private int var1 = 10;
    int var2 = 20;
    protected int var3 = 30;
    public int var4 = 40;

    public void display() {
        System.out.println("var1 (private) = " + var1);
        System.out.println("var2 (default) = " + var2);
        System.out.println("var3 (protected) = " + var3);
        System.out.println("var4 (public) = " + var4);
    }
}
