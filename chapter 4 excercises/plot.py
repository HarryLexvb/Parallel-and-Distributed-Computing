import matplotlib.pyplot as plt
import numpy as np

# dynamic_all_pairs time
dynamic_all_pairs = {
    "Carga de datos": 0.023642,
    "Cálculo de distancias": 23.707,
    "Guardado de resultados": 0.0070773
}

#  dynamic_all_pairs_rev times
dynamic_all_pairs_rev = {
    "Carga de datos": 0.0227069,
    "Cálculo de distancias": 22.859,
    "Guardado de resultados": 0.0080092
}


labels = dynamic_all_pairs.keys()


values_dynamic_all_pairs = list(dynamic_all_pairs.values())
values_dynamic_all_pairs_rev = list(dynamic_all_pairs_rev.values())


x = np.arange(len(labels))


width = 0.35


fig, ax = plt.subplots()
rects1 = ax.bar(x, values_dynamic_all_pairs, width, label='dynamic_all_pairs')
rects2 = ax.bar(x + width, values_dynamic_all_pairs_rev, width, label='dynamic_all_pairs_rev')

ax.set_ylabel('Tiempo (s)')
ax.set_title('Comparación de tiempos de ejecución')
ax.set_xticks(x + width / 2)
ax.set_xticklabels(labels)
ax.legend()

def autolabel(rects):
    for rect in rects:
        height = rect.get_height()
        ax.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')

autolabel(rects1)
autolabel(rects2)


ax.set_yscale('log')


plt.show()
