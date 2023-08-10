"""
File:           op_signals.py
Last changed:   10/08/2023 16:21
Purpose:        observe operations on signals         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 op_signals.py          
"""

import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(0, 10, 1000)  # Time vector from 0 to 10 seconds
f = 1  # Signal frequency in Hz

# Sinusoidal signal
sin = np.sin(2 * np.pi * f * t)  # sin(2*pi*f*t)

# Cosine signal
cos = np.cos(2 * np.pi * f * t)  # cos(2*pi*f*t)ls

plt.figure(figsize=(15, 5))

# Original signal
plt.subplot(1, 3, 1)
plt.plot(t, sin, label='Original Signal')

# Scale change
sin_scaled = 2 * sin
plt.subplot(1, 3, 1)
plt.plot(t, sin_scaled, label='Scaled Sin Signal')
plt.title('Scale change')
plt.legend()

# Adition between signals
plt.subplot(1, 3, 2)
plt.plot(t, cos + sin, label='Sin + Cos')
plt.title('Sin + Cos')

# Multiply Signals
plt.subplot(1, 3, 3)
plt.plot(t, cos * sin, linestyle='-', label='Sin * Cos')
plt.title('Sin * Cos')

plt.tight_layout()
plt.show()
