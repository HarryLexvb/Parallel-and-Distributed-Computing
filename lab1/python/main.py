
import matplotlib.pyplot as plt

sizes = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000]

times_loop1 = [0.0029998, 0.0120882, 0.0265921, 0.0471781, 0.0732076, 0.105906, 0.147737, 0.188289, 0.240823, 0.296267, 1.5655, 4.73304, 10.3511]
times_loop2 = [0.0033018, 0.0276046, 0.0471333, 0.0867026, 0.138842, 0.203319, 0.28977, 0.471309, 0.506272, 0.664494, 2.8187, 7.79636, 17.9068]

plt.plot(sizes, times_loop1, label='Loop 1')
plt.plot(sizes, times_loop2, label='Loop 2')

plt.xlabel('Size')
plt.ylabel('Time (s)')
plt.title('Comparison of Loop Execution Times')
plt.legend()

plt.show()
