import numpy as np
import matplotlib.pyplot as plt

# task 6: plot
E = np.genfromtxt('data/E.txt')
p_nu_e = np.genfromtxt('data/p_nu_e.txt')
p_nu_mu = np.genfromtxt('data/p_nu_mu.txt')
p_nu_tau = np.genfromtxt('data/p_nu_tau.txt')

plt.plot(E * 1e-9, p_nu_e, color = 'blue', label=r'P(\nu_{e} \to \nu_{e})')
plt.plot(E * 1e-9, p_nu_mu, color = 'red', label=r'P(\nu_{e} \to \nu_{\mu})')
plt.plot(E * 1e-9, p_nu_tau, color = 'green', label=r'P(\nu_{e} \to \nu_{\tau})')
plt.xscale('log')
plt.xlabel(r'$E / \mathrm{GeV}$')
plt.ylabel(r'$P(\nu_{e} \to \nu_{\alpha})$')
plt.savefig('plots/probs.pdf')
plt.clf()