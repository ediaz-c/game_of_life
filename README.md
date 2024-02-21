# game_of_life
![game_of_life](https://github.com/ediaz-c/game_of_life/assets/80516778/523892cf-d596-4994-bba5-6565485e6152)
Este proyecto implementa el famoso "Juego de la Vida" creado por el matemático británico John Conway. El Juego de la Vida es un autómata celular bidimensional que sigue reglas simples pero que da lugar a patrones complejos y fascinantes.

El juego se desarrolla en una cuadrícula bidimensional de celdas, donde cada celda puede estar viva o muerta. La evolución de las celdas a lo largo de las generaciones sigue un conjunto de reglas simples:
## Reglas:
- **Sobrepoblación:** Si una célula **viva** tiene más de tres vecinos vivos, **muere** por sobrepoblación.
- **Estabilidad:** Si una célula **viva** tiene dos o tres vecinos vivos, **sobrevive** a la siguiente generación.
- **Subpoblación:** Si una célula **viva** tiene menos de dos vecinos vivos, **muere** por subpoblación.
- **Reproducción:** Si una célula **muerta** tiene exactamente tres vecinos vivos, **nace** en la siguiente generación.

## Uso
```
git clone https://github.com/ediaz-c/game_of_life.git
cd game_of_life
make
```
