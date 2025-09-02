import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Función cuadrática para el ajuste
def quadratic_model(t, a, v0, x0):
    return 0.5 * a * t**2 + v0 * t + x0

def load_data(file_path):
    data = np.loadtxt(file_path)
    time = data[:, 0]
    position = data[:, 1]
    return time, position

files = ['p5_1_datos_1.txt', 'p5_1_datos_2.txt', 'p5_1_datos_3.txt', 
         'p5_1_datos_4.txt', 'p5_1_datos_5.txt']

results = {}
plt.figure(figsize=(14, 10))

# ------------------------------------------------------------
# 1. Procesamiento de datos y ajuste cuadrático
# ------------------------------------------------------------
for i, file in enumerate(files, 1):
    try:
        time, position = load_data(file)
        
        # Ajuste cuadrático inicial
        params, _ = curve_fit(quadratic_model, time, position, maxfev=5000)
        a, v0, x0 = params
        
        # Ajuste con posición inicial = 0
        params_shifted, _ = curve_fit(lambda t, a, v0: quadratic_model(t, a, v0, 0), 
                                    time, position - x0, maxfev=5000)
        a_shifted, v0_shifted = params_shifted
        
        # Validación física (velocidades negativas -> cero)
        v0_shifted = max(v0_shifted, 0)
        
        fitted_values = quadratic_model(time, a_shifted, v0_shifted, 0)
        rms_error = np.sqrt(np.mean((position - x0 - fitted_values)**2))
        
        results[file] = {
            'a': a_shifted,
            'v0': v0_shifted,
            'rms_error': rms_error,
            'equation': f'x(t) = {0.5*a_shifted:.3f}t² + {v0_shifted:.3f}t',
            'time': time,
            'position': position - x0
        }
        
        # Gráfica de posición vs tiempo
        plt.subplot(3, 2, i)
        plt.scatter(time, position - x0, color='red', s=15, label='Datos')
        plt.plot(time, fitted_values, 'b-', label=results[file]['equation'])
        plt.xlabel('Tiempo (s)')
        plt.ylabel('Posición (m)')
        plt.title(f'{file}\nRMS: {rms_error:.5f} m')
        plt.legend()
        plt.grid(True)

    except Exception as e:
        print(f"Error procesando {file}: {e}")

plt.tight_layout()
plt.show()

# ------------------------------------------------------------
# 2. Resultados individuales y filtrado
# ------------------------------------------------------------
print("\nResultados individuales:")
for file, res in results.items():
    print(f"\n{file}:")
    print(f"- Ecuación: {res['equation']}")
    print(f"- Aceleración (a): {res['a']:.3f} m/s²")
    print(f"- Velocidad inicial (v0): {res['v0']:.3f} m/s")
    print(f"- Error RMS: {res['rms_error']:.5f} m")

# Filtrado de resultados
if len(results) >= 3:
    rms_values = [res['rms_error'] for res in results.values()]
    min_rms_file = min(results.keys(), key=lambda x: results[x]['rms_error'])
    max_rms_file = max(results.keys(), key=lambda x: results[x]['rms_error'])
    
    filtered_results = {file: res for file, res in results.items() 
                      if file not in [min_rms_file, max_rms_file]}
    
    print("\nArchivos descartados:")
    print(f"- Máximo RMS: {max_rms_file} (RMS = {results[max_rms_file]['rms_error']:.5f} m)")
    print(f"- Mínimo RMS: {min_rms_file} (RMS = {results[min_rms_file]['rms_error']:.5f} m)")
    
    avg_a = np.mean([res['a'] for res in filtered_results.values()])
    avg_v0 = np.mean([res['v0'] for res in filtered_results.values()])
    
    print("\nResultados filtrados:")
    for file, res in filtered_results.items():
        print(f"{file}: a = {res['a']:.3f} m/s², v0 = {res['v0']:.3f} m/s")
    
    print(f"\nEcuación promedio final:")
    print(f"x(t) = {0.5*avg_a:.3f}t² + {avg_v0:.3f}t")
    print(f"Aceleración promedio: {avg_a:.3f} m/s²")
    print(f"Velocidad inicial promedio: {avg_v0:.3f} m/s")
else:
    print("\nNo hay suficientes datos para filtrar")
    avg_a = np.mean([res['a'] for res in results.values()])
    avg_v0 = np.mean([res['v0'] for res in results.values()])

# ------------------------------------------------------------
# 3. Gráficas de Velocidad y Aceleración (Pasos 11 y 12)
# ------------------------------------------------------------
# Crear array de tiempo suavizado
t_smooth = np.linspace(0, max([max(res['time']) for res in results.values()]), 100)

# 11. Gráfica de Velocidad vs Tiempo
plt.figure(figsize=(10, 5))
velocidad_teorica = avg_a * t_smooth + avg_v0  # v(t) = a*t + v0

# Calcular velocidades experimentales (derivada numérica)
for file, res in filtered_results.items() if len(results) >= 3 else results.items():
    dt = np.diff(res['time'])
    dx = np.diff(res['position'])
    v_exp = dx / dt
    plt.scatter(res['time'][:-1], v_exp, alpha=0.5, label=f'Datos {file}')

plt.plot(t_smooth, velocidad_teorica, 'r-', linewidth=2, 
        label=f'Teórica: v(t) = {avg_a:.3f}t + {avg_v0:.3f}')
plt.xlabel('Tiempo (s)')
plt.ylabel('Velocidad (m/s)')
plt.title('Velocidad vs Tiempo')
plt.grid(True)
plt.legend()
plt.show()

# 12. Gráfica de Aceleración vs Tiempo
plt.figure(figsize=(10, 5))
aceleracion_teorica = np.full_like(t_smooth, avg_a)  # Array constante

# Calcular aceleraciones experimentales (derivada segunda)
for file, res in filtered_results.items() if len(results) >= 3 else results.items():
    dt = np.diff(res['time'][:-1])
    dv = np.diff(v_exp)
    a_exp = dv / dt
    plt.scatter(res['time'][:-2], a_exp, alpha=0.5, label=f'Datos {file}')

plt.plot(t_smooth, aceleracion_teorica, 'g-', linewidth=2, 
        label=f'Teórica: a = {avg_a:.3f} m/s²')
plt.xlabel('Tiempo (s)')
plt.ylabel('Aceleración (m/s²)')
plt.title('Aceleración vs Tiempo')
plt.grid(True)
plt.legend()
plt.show()