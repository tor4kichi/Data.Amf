@echo off
set IA32=Win32
set IA32M=x86
set AMD64=x64
set ARM=ARM

set WIN8=win8
set WIN81=win81
set WPS8=wp8
set WPS81=wp81
set WPR81=wpa81
set UWP=uap10.0

set REL=Release
set NAME=Mntone.Data.Amf
set EXT=dll winmd pri

rem license.md
cd "../"
copy "license.md" "./nuget/data/license.md"

rem Windows Runtime 8.1 component (IA-32/AMD64/ARM)
cd "./bin/%IA32%-%REL%/%NAME%.Windows/"
md "../../../nuget/data/lib/%WIN81%/%IA32M%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%WIN81%/%IA32M%/" /Y
cd "../../%AMD64%-%REL%/%NAME%.Windows/"
md "../../../nuget/data/lib/%WIN81%/%AMD64%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%WIN81%/%AMD64%/" /Y
cd "../../%ARM%-%REL%/%NAME%.Windows/"
md "../../../nuget/data/lib/%WIN81%/%ARM%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%WIN81%/%ARM%/" /Y

rem Windows Phone Silverlight 8 component (IA-32/ARM)
cd "../../%IA32%-%REL%/%NAME%.WindowsPhone8/"
md "../../../nuget/data/lib/%WPS8%/%IA32M%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%WPS8%/%IA32M%/" /Y
cd "../../%ARM%-%REL%/%NAME%.WindowsPhone8/"
md "../../../nuget/data/lib/%WPS8%/%ARM%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%WPS8%/%ARM%/" /Y

rem Windows Phone Runtime 8.1 component (IA-32/ARM)
cd "../../%IA32%-%REL%/%NAME%.WindowsPhone/"
md "../../../nuget/data/lib/%WPR81%/%IA32M%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%WPR81%/%IA32M%/" /Y
cd "../../%ARM%-%REL%/%NAME%.WindowsPhone/"
md "../../../nuget/data/lib/%WPR81%/%ARM%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%WPR81%/%ARM%/" /Y

rem Windows Universal Platform component (IA-32/AMD64/ARM)
cd "../../%IA32%-%REL%/%NAME%.UWP/"
md "../../../nuget/data/lib/%UWP%/%IA32M%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%UWP%/%IA32M%/" /Y
cd "../../%AMD64%-%REL%/%NAME%.UWP/"
md "../../../nuget/data/lib/%UWP%/%AMD64%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%UWP%/%AMD64%/" /Y
cd "../../%ARM%-%REL%/%NAME%.UWP/"
md "../../../nuget/data/lib/%UWP%/%ARM%/"
for %%e in (%EXT%) do copy "%NAME%.%%e" "../../../nuget/data/lib/%UWP%/%ARM%/" /Y


PAUSE