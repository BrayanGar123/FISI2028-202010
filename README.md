# Métodos Computacionales - Primer Semestre 2020

### Entornos de programación académica en línea:
* [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/jpmallarino/FISI2028-202010/master?urlpath=lab/tree/ipynb)
* Azure cloud service de [Uniandes ![Uniandes](imagenes/andes_32px.png)](http://facciencias.az.uniandes.edu.co/jhub/)
* Para crear su ambiente propio siga las siguientes instrucciones:
1. Primero instalar [Miniconda](https://docs.conda.io/en/latest/miniconda.html)
2. Instalar la base para JupyterLab (sólo en Unix): `conda install -n base jupyterlab nb_conda_kernels`
3. Instalar el ambiente (sólo en Unix): `conda env create -f environment.yml`
4. Entrar al ambiente (sólo en Unix)): `conda activate fisi2028`
4. Configurar el canal `conda-forge` con prioridad mayor que el canal por defecto (sólo en Unix): `conda config --env --add channels conda-forge`
5. Salirse del ambiente fisi2028 y entrar en la base (sólo en Unix): `conda deactivate`
6. Levantar el cuaderno ejecutando la siguiente instrucción (sólo en Unix): `jupyter lab --ip 0.0.0.0 --port 8888`
7. De esta manera pueden acceder desde cualquier equipo que esté conectado a la misma red en donde está corriendo el cuaderno de Jupyter. Es muy útil cuando están compartiendo un equipo con alguien pero aún necesitan acceder al cuaderno. Se puede hacer desde el navegador de una tableta por ejemplo.

## Material del curso Métodos Computacionales de Uniandes

> Nota: el material aquí publicado es tomado del [proyecto académico de enseñanza de Física Computacional ![ComputoCienciasUniandes](imagenes/GitHub-Mark-32px.png)](http://computocienciasuniandes.github.io/) liderado por el Profesor Jaime Ernesto Forero

**Universidad de los Andes | Vigilada Mineducación
Reconocimiento como Universidad: Decreto 1297 del 30 de mayo de 1964.
Reconocimiento personería jurídica: Resolución 28 del 23 de febrero de 1949 Minjusticia.**

*Carrera 1 18A-10, Bloque Ip. Bogota - Colombia. A.A. 4976-12340.*   
*Telephone +571 3324500.*
*Fax +571 3324516*

Universidad de los Andes
Facultad de Ciencias
Departamento de Física

