# Java vs. C++: A Memory Efficiency Deep Dive

This project provides a practical demonstration of the fundamental differences in memory allocation between Java and C++. By running two simple programs that allocate a large number of objects, you can directly observe why C++ often results in a more compact and efficient memory footprint.

The key takeaway is this: C++ creates a single, dense block of memory for an array of objects, while Java creates an array of pointers that point to individual objects scattered across the heap, incurring significant overhead.
The Core Difference: Memory Layout

The "why" behind the efficiency difference comes down to how arrays of objects are stored in memory.
C++: The "Array of Objects" Model (Contiguous)

When you execute new Point[SIZE] in C++, you are allocating one single, contiguous block of memory.

Imagine a large bookshelf. C++ places each Point object directly on this shelf, side-by-side, with no space in between.

>Memory Footprint: The total memory used is simple and predictable: SIZE * sizeof(Point).
>Zero Overhead: Each object consists only of its data members (int x, int y). There is no extra per-object metadata.
>Cache-Friendly: Because all the data is packed together, the CPU can load large chunks of it into its high-speed cache at once, leading to faster processing.

Java: The "Array of References" Model (Scattered)

When you execute new Point[SIZE] in Java, you are not allocating the Point objects. Instead, you are allocating an array of references (pointers).

Think of this as a directory in a building lobby. The directory itself (Point[]) just contains a list of room numbers (references). Each actual Point object is a separate room located somewhere else in the building (the heap). You must then loop through and create each Point object individually (p[i] = new Point()), which finds an empty room and places the object there.

>Memory Footprint: The total memory is the sum of many small, separate allocations:
    >>* The array of references itself.
    >>* SIZE individual Point objects, scattered across the heap.
>
>Per-Object Overhead: Every single Java object carries a "header" containing metadata for the garbage collector and the JVM. This adds 8-16 bytes of overhead to every object, which adds up significantly when creating millions of them.
>Cache-Unfriendly: Accessing the objects sequentially requires the CPU to jump from a reference in the array to a potentially distant memory location for the object itself. This "pointer chasing" is much slower than reading from a contiguous block.

Files in This Project

    Memory.cpp: The C++ program demonstrating contiguous allocation.

    Memory.java: The Java program demonstrating scattered allocation via references.

    Makefile: Compiles the C++ program into an executable named my_program.

    run-java: A simple script to compile and run the Java program.

    show-memory: A utility script to continuously monitor the system's available memory.

How to Use

To see the comparison, you will need two terminal windows open in the project directory.

Terminal 1: Monitor Memory

    Make the show-memory script executable:

    chmod +x show-memory

    Run the script. It will start printing the available memory every second.

    ./show-memory

Terminal 2: Run the Programs

Now, use this terminal to run the C++ and Java programs one by one and watch the memory change in the other terminal.

#### 1. Run the C++ version:

    Compile and run the program using make:

    make

    Watch the MemAvailable value drop in Terminal 1.

    Once the program finishes, clean up the compiled files:

    make clean

#### 2. Run the Java version:

    Make the run-java script executable:

    chmod +x run-java

    Compile and run the program:

    ./run-java

    Watch the MemAvailable value drop again and compare the change to the C++ version. You should notice a significantly larger drop for the Java program.

### About the show-memory Script

This script provides a live view of your system's available memory by reading from /proc/meminfo.
```bash
#!/bin/bash

while :
do
    cat /proc/meminfo | grep MemAvailable
    sleep 1   # wait for one second, and repeat
done
```

``
How to free the buffers; from here: https://unix.stackexchange.com/q/87908/16569.

free && sync && echo 3 | sudo tee /proc/sys/vm/drop_caches && free
```


Clearing Caches

Operating systems use available RAM for disk caching. To get a more accurate measurement of program memory usage, you can manually clear these caches between runs using the command commented out in the script.

Warning: This requires administrator privileges.

Run this command in your terminal between tests for a clearer result.

`free && sync && echo 3 | sudo tee /proc/sys/vm/drop_caches && free`

