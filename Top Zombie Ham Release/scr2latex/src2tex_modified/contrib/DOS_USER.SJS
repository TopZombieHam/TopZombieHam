============= DOS_USER.SJS =========================================

�c�n�r��� src2tex ���g�p�������ցF
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

�V�삳�񂩂� src2tex �̃\�[�X�������������̂ŁA������ DynaBookEZ486
�ɃC���X�g�[�����悤�Ǝv���܂����i�g�p�n�r�F���œ��p�c�n�r V5�j�B�t
�@�C�����𓀂��ADJGCC �ɂ�����Ɖ��̖����Ȃ� make dos �ɐ������܂�
���B�E��� PC9801 �� Turbo C �ł������܂������A������ł͂t�m�h�w�`
���̃t�@�C�����c�n�r�`���ɕϊ����Ă�����s���Ȃ��ƃG���[�ɂȂ�܂����B
������� Makefile ������������܂����BWarning ���ЂƂł܂������A��
�肠�������s�t�@�C�����ł����悤�ł��B


src2tex �͓��{��R�[�h�Ƃ��� EUC ��O��Ƃ��Ă��邽�߁A�l�r�|�c�n�r
��Ŏg�����߂ɂ́A���炩���߃R�[�h��ϊ����Ă����K�v������܂��B

�Ⴆ�� nkf �Ȃǂ�p�ӂ��Ă�����
        nkf -e sample.c | src2tex | nkf -s > sample.tex
        tex sample
�Ƃ��ΊȒP�Ɏ��s�ł��܂����A���̕��@�ł� src2tex �Ƀt�@�C�������n��
��܂���B�y�[�W�̉E���Ƀt�@�C������\�����������Ƃ��͉��� src2dvi.
bat �Ƃ����o�b�`�t�@�C�����g���ƕ֗��ł��B���Ƃ��΁A
�@�@�@�@src2dvi sample.c
�ȂǂƂ���΁Asample.tex ���J�����g�E�f�B���N�g���ɍ���A����� TeX
���N������ sample.dvi �������܂��B

�������A���������ӂ���_������܂��B
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

�P�D�g�p������s�t�@�C�����ɂ��킹�ăo�b�`�t�@�C�������������Ă�����
�@�@���B���� src2tex.exe, tex.exe ���g�p�����悤�ɂȂ��Ă��܂��B�K
�@�@�v�ɉ�����
�@�@�@�@�@src2tex -> src2ltex, go32 src2tex, .....
�@�@�@�@�@tex     -> jtex, latex, jlatex, ......
�@�@�̂悤�ɂ��܂��B

�Q�D�Ώۃt�@�C���̂���f�B���N�g�����J�����g�f�B���N�g���ɂ��Ď��s��
�@�@�܂��B���Ƃ��΁Ac:\ �ɂ��āAsrc2dvi d:\sample.c �ȂǂƂ��Ȃ��ł�
�@�@�������B

�R�D���s�ɂ� BU.COM (Batch Utility) ����� NKF.EXE  ( Network  Kanji
�@�@Filter) �܂��͗ގ��̃\�t�g�E�F�A���K�v�ł��BBU10?.LZH �͑傫�Ȃa
�@�@�a�r�ł݂���Ǝv���܂��BJBA-Net �ɂ͂���܂��B�A�X�L�[�́u�G��
�@�@�t���[�\�t�g�E�F�A�P�O�O�I�v�ɂ��͂����Ă��܂��Bnkf �� internet 
�@�@�� news �łƂ��ǂ��V�������̂��݂������܂��B�uUNIX USER�v����
�@�@�P�X�X�S�NNo.10�̕t�^�b�c�|�q�n�l�� fj.binaries.msdos �̂Ƃ����
�@�@�� NKF94701.LZH ���͂����Ă��܂��B

�S�D���p�J�^�J�i�������Ă���ꍇ�́A�܂��A�S�p�ɒ����Ă�����s����
�@�@���傤�B���ɓY�t�� kana.sed ���g�p����ƕ֗��ł��B
�@�@�@�@sed -f kana.sed input_file > output_file
�@�@�ŁA�ϊ��ł��܂��B���̑�����A�p�ɂɍs���K�v������Ƃ��́A���̃X
�@�@�e�b�v���o�b�`�t�@�C���ɑg�ݍ��݂܂��傤�B

�T�D�g���q�� .tex �̃t�@�C������������ꍇ�́i���{�ꏈ���̌�j��U�e
�@�@���|�����ȃf�B���N�g���Ɋg���q����苎�������O�ŃR�s�[���A�����
�@�@src2tex �ɂ����Ă��܂��B����E�v���r���[�̍ۍŉ����̃t�@�C������
�@�@�g���q���Ȃ����̂ɂȂ�܂����A�����  src2dvi.bat �̎d�l�ł��B��
�@�@�������������B�܂����̂Ƃ��A���ꂽ .tex �t�@�C���͌��̃t�@�C��
�@�@���c�����߂ɁATeX �̎��s���������܂��B���炩�̗��R�ł�����c��
�@�@�����ꍇ�́A����  tex2tex.bat �̕����g���Ă��������B�T�u�f�B���N
�@�@�g�� __SRC2 �̒��Ɏc����Ă���͂��ł��B�܂��A�g���q�� .log �̃t
�@�@�@�C���� src2dvi.bat �ŏ�������ꍇ���ATeX �̍�� log �t�@�C����
�@�@����ď㏑�������̂�h�����߁A TeX �̍�� log �t�@�C���͏�����
�@�@��܂��B

�U�Dsrc2tex �����s���Ăł��� .tex �t�@�C���Ɠ����̃t�@�C�������łɑ�
�@�@�݂���ꍇ�A�㏑�����Ă悢�������˂�悤�ɂ��邱�Ƃ��ł��܂��B�o
�@�@�b�`�t�@�C�����̎w�����Ă��镔���̍s���� REM ���폜���Ă��������B

�V�Ddvi �t�@�C�����v���r���[����悤�ɃR�}���h��ǉ�����ƕ֗��ł��B

�W�D�o�b�`�t�@�C�����ł�  SRC �Ƃ������ϐ����g�p���Ă��܂��B�s�s��
�@�@������΁A�ύX���Ă��������B  �܂��A�J�����g�E�f�B���N�g���̉���
�@�@__src2  �Ƃ����e���|�����ȃT�u�f�B���N�g��������č�Ƃ��s����
�@�@���B������s�s��������΁A�ύX���Ă��������B�Ȃ��A���v���O������
�@�@�`���C���h�E�v���Z�X�Ŏ��s����ꍇ�AVer.5 �ȍ~�̂c�n�r�ł͊���
�@�@���̈悪����Ȃ��Ȃ邱�Ƃ�����܂��B���̂Ƃ��́AMOREENV �Ȃǂ̃c
�@�@�[���Ŋ��ϐ��̈��傫���Ƃ��Ă��������B�@�܂��AJBA-Net �ɂ���
�@�@ENV �Ƃ����c�[�����g���΁A���ϐ��̈�T�C�Y��g�p�ʂ��ȒP�ɂ킩
�@�@��܂��B�i���̌��Ɋւ��Ă� DynaBook Net �̊F����ɐF�X�����܂�
�@�@���B���Ɋ��ϐ��̈�T�C�Y���`�F�b�N���镔���́@�������@�����
�@�@�o�b�`�t�@�C������A��������܂˂����Ă��������܂����B�j

�X�DVer.3 �� �c�n�r�Ŏg����ꍇ�́A�o�b�`�t�@�C���擪�� @ ���Ƃ���
�@�@���������B�i����̊m�F�͂��Ă܂���j


�����g�Ńv���O�������������Ƃ͖ő��ɂȂ��̂ł����A���낢��ȃt�@�C��
�i�d�q���[���Ȃǁj�����ꂢ�Ɉ������̂ɂƂĂ��d�󂵂Ă��܂��B
�����g�̗p�r�ɍ��킹���o�b�`�t�@�C���ł��̂ŁA�s�K�v�ȕ�������������
����܂���B���R�ɏC�����邢�͍ŏ����珑�����낵�Ă��������B



�R��@���V�@�����U�N�P�O���Q�X��
(H7.2.18 �ꕔ�C��)
internet    : myamasa@tansei.cc.u-tokyo.ac.jp
              yamasaki@crescent.josai.ac.jp
DynaBook NeT: DY312847
JBA-Net     : JBA42253

src2dvi.bat:
--------------------- cut here ---------------------
@ECHO OFF
IF EXIST %1 GOTO checkenv
ECHO   .....  cannot find "%1"!!
GOTO end
:checkenv
SET SRC=12345678
IF "%SRC%"=="12345678" GOTO getname
ECHO Not enough ENVIRONMENT SIZE!
GOTO end
:getname
BU -nSRC -c STRTOKFILE %1
md __src2
ECHO ...... now converting to EUC ......
nkf -e %1 > __src2\%1
cd __src2
IF EXIST %SRC%.tex GOTO exterror
IF EXIST %SRC%.log GOTO exterror
src2tex %1
cd ..
REM Uncomment the following 5 lines, if you like.
REM IF NOT EXIST %SRC%.tex GOTO shori
REM ECHO A file named "%SRC%.tex" already exists!
REM BU KEYYESNO Overwrite %SRC%.tex? (Y/N)
REM IF ERRORLEVEL 1 GOTO end
REM :shori
ECHO ...... now converting to Shift-JIS ......
nkf -s __src2\%SRC%.tex > %SRC%.tex
del __src2\%SRC%.tex
del __src2\%1
rd __src2
TeX %SRC%
GOTO preview
:exterror
ren %1 %SRC%
src2tex %SRC%
del %SRC%
ren %SRC%.tex %SRC%
ECHO ...... now converting to Shift-JIS ......
nkf -s %SRC% > %SRC%.tex
tex %SRC%
cd ..
copy __src2\%SRC%.dvi %SRC%.dvi
del __src2\%SRC%
del __src2\%SRC%.tex
del __src2\%SRC%.log
del __src2\%SRC%.dvi
rd __src2
:preview
REM DVIOUT %SRC%
:end
set SRC=
--------------------- cut here ---------------------


tex2tex.bat:
--------------------- cut here ---------------------
@ECHO OFF
SET SRC=12345678
IF "%SRC%"=="12345678" GOTO getname
ECHO Not enough ENVIRONMENT SIZE!
GOTO end
:getname
BU -nSRC -c STRTOKEXT %1
BU STRICMP %SRC% TeX
IF ERRORLEVEL 1 GOTO wrongext
IF EXIST %1 GOTO shori
ECHO "%1" does not exist!
GOTO end
:wrongext
BU -nSRC -c STRTOKFILE %1
IF EXIST %SRC%.tex GOTO suggest
ECHO NO SUCH FILE!
GOTO end
:suggest
ECHO The extension of "%1" is not "TEX"!
BU KEYYESNO Do you mean "%SRC%.tex"? (Y/N)  
IF ERRORLEVEL 1 GOTO end
ECHO.
:shori
BU -nSRC -c STRTOKFILE %1
md __src2
ECHO ...... now converting to EUC ......
nkf -e %SRC%.tex > __src2\%SRC%
cd __src2
src2tex %SRC%
del %SRC%
ren %SRC%.tex %SRC%
ECHO ...... now converting to Shift-JIS ......
nkf -s %SRC% > %SRC%.tex
del %SRC%
tex %SRC%
:preview
REM dviout %SRC%
REM cd ..
:end
set SRC=
--------------------- cut here ---------------------
end of tex2tex.bat


kana.sed:
--------------------- cut here ---------------------
# kana.sed
# ���p�J�^�J�i��S�p�ɕϊ�
# sed -f kana.sed input > output

s/��/�K/g
s/��/�M/g
s/��/�O/g
s/��/�Q/g
s/��/�S/g
s/��/�U/g
s/��/�W/g
s/��/�Y/g
s/��/�[/g
s/��/�]/g
s/��/�_/g
s/��/�a/g
s/��/�d/g
s/��/�f/g
s/��/�h/g
s/��/�p/g
s/��/�s/g
s/��/�v/g
s/��/�y/g
s/��/�|/g
s/��/�o/g
s/��/�r/g
s/��/�u/g
s/��/�x/g
s/��/�{/g
y/���������������������/�B�u�v�A�E���@�B�D�F�H�������b�[�A�C�E�G�I/
y/��������������������/�J�L�N�P�R�T�V�X�Z�\�^�`�c�e�g�i�j�k�l�m/
y/����������������������/�n�q�t�w�z�}�~���������������������������J�K/

# end of kana.sed
----------------------- cut here -------------------------
end of kana.sed