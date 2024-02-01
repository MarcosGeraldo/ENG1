QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EasyCar/Interface/mainwindow.cpp \
    EasyCar/src/lib/rentHB.cpp \
    EasyCar/src/lib/systemHB.cpp \
    EasyCar/src/lib/userHB.cpp \
    EasyCar/src/lib/vehicleHB.cpp \
    EasyCar/test/funcional/main.cpp \
    EasyCar/test/funcional/testesFuncionais.cpp \
    EasyCar/test/unit/main.cpp \
    EasyCar/test/unit/teste_Unit_Fluxo.cpp \
    EasyCar/test/unit/teste_Unit_Modelo.cpp \
    EasyCar/test/unit/teste_Unit_Sistema.cpp \
    MyVensim/Interface/mainwindow.cpp \
    MyVensim/src/lib/rentHB.cpp \
    MyVensim/src/lib/systemHB.cpp \
    MyVensim/src/lib/userHB.cpp \
    MyVensim/src/lib/vehicleHB.cpp \
    MyVensim/test/funcional/main.cpp \
    MyVensim/test/funcional/testesFuncionais.cpp

HEADERS += \
    EasyCar/Interface/mainwindow.h \
    EasyCar/src/lib/handleBodySemDebug.h \
    EasyCar/src/lib/rent.h \
    EasyCar/src/lib/rentHB.h \
    EasyCar/src/lib/system.h \
    EasyCar/src/lib/systemHB.h \
    EasyCar/src/lib/user.h \
    EasyCar/src/lib/userHB.h \
    EasyCar/src/lib/vehicle.h \
    EasyCar/src/lib/vehicleHB.h \
    EasyCar/test/funcional/testesFuncionais.h \
    EasyCar/test/unit/teste_Unit_Fluxo.h \
    EasyCar/test/unit/teste_Unit_Modelo.h \
    EasyCar/test/unit/teste_Unit_Sistema.h \
    MyVensim/Interface/mainwindow.h \
    MyVensim/src/lib/handleBodySemDebug.h \
    MyVensim/src/lib/rent.h \
    MyVensim/src/lib/rentHB.h \
    MyVensim/src/lib/system.h \
    MyVensim/src/lib/systemHB.h \
    MyVensim/src/lib/user.h \
    MyVensim/src/lib/userHB.h \
    MyVensim/src/lib/vehicle.h \
    MyVensim/src/lib/vehicleHB.h \
    MyVensim/test/funcional/testesFuncionais.h

FORMS += \
    EasyCar/Interface/mainwindow.ui \
    MyVensim/Interface/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    EasyCar/.git/COMMIT_EDITMSG \
    EasyCar/.git/HEAD \
    EasyCar/.git/config \
    EasyCar/.git/description \
    EasyCar/.git/hooks/applypatch-msg.sample \
    EasyCar/.git/hooks/commit-msg.sample \
    EasyCar/.git/hooks/fsmonitor-watchman.sample \
    EasyCar/.git/hooks/post-update.sample \
    EasyCar/.git/hooks/pre-applypatch.sample \
    EasyCar/.git/hooks/pre-commit.sample \
    EasyCar/.git/hooks/pre-merge-commit.sample \
    EasyCar/.git/hooks/pre-push.sample \
    EasyCar/.git/hooks/pre-rebase.sample \
    EasyCar/.git/hooks/pre-receive.sample \
    EasyCar/.git/hooks/prepare-commit-msg.sample \
    EasyCar/.git/hooks/push-to-checkout.sample \
    EasyCar/.git/hooks/update.sample \
    EasyCar/.git/index \
    EasyCar/.git/info/exclude \
    EasyCar/.git/logs/HEAD \
    EasyCar/.git/logs/refs/heads/master \
    EasyCar/.git/logs/refs/heads/testeGit \
    EasyCar/.git/logs/refs/remotes/origin/master \
    EasyCar/.git/objects/03/146b3853705d650a353d85fccd26352a0960a6 \
    EasyCar/.git/objects/08/cd8d8dbb1bd333d4df7e3e057f2e864e0940c6 \
    EasyCar/.git/objects/0a/fd732f9670b891da24a08d3dde825bff42671d \
    EasyCar/.git/objects/14/0a13b56bfe58e3b745275f3965466ab5233b6c \
    EasyCar/.git/objects/28/feb7915bea576b013e5b3c7e537f3eae9a94b1 \
    EasyCar/.git/objects/2b/2650e4f8cdda680a787f80dc08868af378eab2 \
    EasyCar/.git/objects/2d/3baaa2f587882392577e179ca9a9fcaccceca3 \
    EasyCar/.git/objects/2d/b44642b6f4367c2b15c77f67d23be0b283d971 \
    EasyCar/.git/objects/2d/dce48eea04119d1fb6a2bfad5483c9934356f3 \
    EasyCar/.git/objects/2d/eaa1e038f21f6dfff42de8880027bb77cb5efe \
    EasyCar/.git/objects/33/fff3e13468b7925ee87a9f41247a4c9d3a8190 \
    EasyCar/.git/objects/37/0a06c7a585115140cc22f2a52558c8b2fb559f \
    EasyCar/.git/objects/3b/cf86214554ef1056d97e1bfe7c4a0e0ac398f6 \
    EasyCar/.git/objects/4b/2a4c47ba7ca3ace1e4f363a66fab9e554a6a13 \
    EasyCar/.git/objects/53/3314e777c5533a76c33ba3954bd07a47d2f1f9 \
    EasyCar/.git/objects/55/8466b3304c7b952abe4046a4e32db44cbbd1a8 \
    EasyCar/.git/objects/5f/133c9dd6eac36b747f7f72423d8884602027db \
    EasyCar/.git/objects/63/677155f3b3d7ba82ea79901d2c31d161c0ebc1 \
    EasyCar/.git/objects/64/0d7684fa7a70f2798d6c812326ae8623ebd076 \
    EasyCar/.git/objects/64/d0c1cf529aeee6cad6761ace9eba9a43d92279 \
    EasyCar/.git/objects/6d/96d43ebb3a749969d36efb733a42559c60f0bf \
    EasyCar/.git/objects/84/d7139a254f639a528cbeb892ca35257c04d01f \
    EasyCar/.git/objects/a0/201daad8fe5daa100b504153021b2e6212b6a8 \
    EasyCar/.git/objects/a3/50fa15110476cd2df6592c677ddf358e7de7fd \
    EasyCar/.git/objects/a3/a19b59ab4684cbf9713077432669b8ed00b3c4 \
    EasyCar/.git/objects/a4/70757461fc5a828bf9d1136190cdedf7e48caa \
    EasyCar/.git/objects/bf/604b0674aadac5ba98f9dbf8ab1a370477639c \
    EasyCar/.git/objects/bf/ebe6f7027e2c39500f6b5abf7a3bfd9cce93a7 \
    EasyCar/.git/objects/bf/ff57fbb3f39bfc5e423635d2a2415a50000d97 \
    EasyCar/.git/objects/c2/d5473b87f620feaff627844d170d3cc2be6232 \
    EasyCar/.git/objects/ca/4e96f12bb2952c0bb9fd1ced984769a46452c2 \
    EasyCar/.git/objects/d1/e9221a548b9e6e753d37a66c4f36e9dc823d80 \
    EasyCar/.git/objects/d4/c9dd614ff555bce4cd00d4561120c41cf7da66 \
    EasyCar/.git/objects/d9/026ac55d676de3d535c8ff60efaf3cc0679fb1 \
    EasyCar/.git/objects/dc/0eb2dae9888968450e4c30960e6932505f9ce3 \
    EasyCar/.git/objects/df/cd33ea26f16b0c2d2481795dd5965120dcf0fe \
    EasyCar/.git/objects/e0/5f6d2d9d73961b55fc8a5cb68ae5b02b48b859 \
    EasyCar/.git/objects/e1/03d0a7e4606ab78e60eb0c5680350277b48aa9 \
    EasyCar/.git/objects/e5/3cbcb0daa620eb4c2bf22e5912a34541593d47 \
    EasyCar/.git/objects/e6/9de29bb2d1d6434b8b29ae775ad8c2e48c5391 \
    EasyCar/.git/objects/f8/6f7f8bfc8e0e5a437a5a926f702ceb9f8d9eb7 \
    EasyCar/.git/objects/f8/d5b0a64b5106e212179877b7e6c751337668cf \
    EasyCar/.git/objects/fa/5319ea1e7fc79510be9d7a42e049242db4600e \
    EasyCar/.git/refs/heads/master \
    EasyCar/.git/refs/heads/testeGit \
    EasyCar/.git/refs/remotes/origin/master \
    EasyCar/.gitignore \
    EasyCar/LinkGitHub.txt \
    EasyCar/bin/funcTest.exe \
    EasyCar/bin/funcTeste.exe \
    EasyCar/bin/libfluxoImpl.so \
    EasyCar/bin/libmodeloImpl.so \
    EasyCar/bin/libsistemaImpl.so \
    EasyCar/bin/unitTeste.exe \
    EasyCar/src/lib/libfluxoImpl.so \
    EasyCar/src/lib/libmodeloImpl.so \
    EasyCar/src/lib/libmyVensim.so \
    EasyCar/src/lib/libsistemaImpl.so \
    EasyCar/src/libfluxoImpl.so \
    EasyCar/src/libmodeloImpl.so \
    EasyCar/src/libsistemaImpl.so \
    EasyCar/test/unit/libfluxoImpl.so \
    EasyCar/test/unit/libmodeloImpl.so \
    EasyCar/test/unit/libsistemaImpl.so \
    MyVensim/src/lib/Makefile
