@ECHO OFF

set basedir=%~dp0
"%basedir%"stm32cubeidec.exe --launcher.suppressErrors -nosplash -application org.eclipse.cdt.managedbuilder.core.headlessbuild %*
