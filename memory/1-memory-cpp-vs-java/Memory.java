// A simple object with three integers
class Color {
    private int red, green, blue;
    
    public Color(int r, int g, int b) {
        this.red = r;
        this.green = g;
        this.blue = b;
    }
}



public class Memory {
    static final int KB = 1024;
    static final int SIZE = 2 * 1000 * KB;

    public static void main(String[] args) throws InterruptedException {
        System.out.println("Before new. Allocating in Java " + SIZE + " Colors ");
        Thread.sleep(3000);

        Color[] colors = new Color[SIZE];

        for (int i = 0; i < SIZE; ++i) {
            colors[i] = new Color(i % 256, (i * 2) % 256, (i * 3) % 256);
        }

        System.out.println("After new");
        Thread.sleep(10000);
    }
}