@Echo OFF

Title Proyecto Geometria Computacional

Color FC

Echo Se Actualizara Las Librerias y El codigo Automaticamente.
Echo.

Echo Por Favor Guarde sus cambios en Notepad++ de lo contrario se forzara su cierre.
    Pause
    TaskList | find /I "notepad++.exe"
        if %errorlevel% == 0 (
            TaskKill /F /IM notepad++.exe
        )
Echo.

cd C:/

Echo Copiando Drivers
    robocopy C:\TC20\XORProject\Driver C:\TC20\BIN /E /MT:16 /NJH /NFL /NJS
Echo.

Echo Copiando Librerias
    robocopy C:\TC20\XORProject\Librerias C:\TC20\INCLUDE /E /MT:16 /NJH /NFL /NJS
Echo.

Echo Copiando Codigo Principal
    robocopy C:\TC20\XORProject\ C:\TC20\ Apple.C /MT:16 /NJH /NFL /NJS
Echo.

Echo Creando Configuracion de Archivos
    if exist C:\TC20\XORProject\files.config (
        erase C:\TC20\XORProject\files.config
    )

    dir C:\TC20\XORProject\Librerias\ >> C:\TC20\XORProject\files.config

Start notepad++ %1C:\TC20\XORProject\files.config

Pause
Exit