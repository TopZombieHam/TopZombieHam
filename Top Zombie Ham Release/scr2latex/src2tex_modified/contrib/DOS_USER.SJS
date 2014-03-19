============= DOS_USER.SJS =========================================

ＤＯＳ上で src2tex を使用される方へ：
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

天野さんから src2tex のソースをいただいたので、自分の DynaBookEZ486
にインストールしようと思いました（使用ＯＳ：東芝日英ＤＯＳ V5）。フ
ァイルを解凍し、DJGCC にかけると何の問題もなく make dos に成功しまし
た。職場の PC9801 の Turbo C でも試しましたが、こちらではＵＮＩＸ形
式のファイルをＤＯＳ形式に変換してから実行しないとエラーになりました。
もちろん Makefile も少しいじりました。Warning がひとつでましたが、と
りあえず実行ファイルができたようです。


src2tex は日本語コードとして EUC を前提としているため、ＭＳ－ＤＯＳ
上で使うためには、あらかじめコードを変換しておく必要があります。

例えば nkf などを用意しておいて
        nkf -e sample.c | src2tex | nkf -s > sample.tex
        tex sample
とやれば簡単に実行できますが、この方法では src2tex にファイル名が渡さ
れません。ページの右下にファイル名を表示させたいときは下の src2dvi.
bat というバッチファイルを使うと便利です。たとえば、
　　　　src2dvi sample.c
などとすれば、sample.tex がカレント・ディレクトリに作られ、さらに TeX
が起動され sample.dvi がつくられます。

ただし、いくつか注意する点があります。
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

１．使用する実行ファイル名にあわせてバッチファイルを書き換えてくださ
　　い。現在 src2tex.exe, tex.exe が使用されるようになっています。必
　　要に応じて
　　　　　src2tex -> src2ltex, go32 src2tex, .....
　　　　　tex     -> jtex, latex, jlatex, ......
　　のようにします。

２．対象ファイルのあるディレクトリをカレントディレクトリにして実行し
　　ます。たとえば、c:\ にいて、src2dvi d:\sample.c などとしないでく
　　ださい。

３．実行には BU.COM (Batch Utility) および NKF.EXE  ( Network  Kanji
　　Filter) または類似のソフトウェアが必要です。BU10?.LZH は大きなＢ
　　ＢＳでみつかると思います。JBA-Net にはあります。アスキーの「秀作
　　フリーソフトウェア１００選」にもはいっています。nkf は internet 
　　の news でときどき新しいものがみかけられます。「UNIX USER」誌の
　　１９９４年No.10の付録ＣＤ－ＲＯＭの fj.binaries.msdos のところに
　　は NKF94701.LZH がはいっています。

４．半角カタカナをつかっている場合は、まず、全角に直してから実行しま
　　しょう。下に添付の kana.sed を使用すると便利です。
　　　　sed -f kana.sed input_file > output_file
　　で、変換できます。この操作を、頻繁に行う必要があるときは、このス
　　テップをバッチファイルに組み込みましょう。

５．拡張子が .tex のファイルを処理する場合は（日本語処理の後）一旦テ
　　ンポラリなディレクトリに拡張子を取り去った名前でコピーし、それを
　　src2tex にかけています。印刷・プレビューの際最下部のファイル名は
　　拡張子がないものになりますが、これは  src2dvi.bat の仕様です。ご
　　了承ください。またこのとき、作られた .tex ファイルは元のファイル
　　を残すために、TeX の実行後消去されます。何らかの理由でこれを残し
　　たい場合は、下の  tex2tex.bat の方を使ってください。サブディレク
　　トリ __SRC2 の中に残されているはずです。また、拡張子が .log のフ
　　ァイルを src2dvi.bat で処理する場合も、TeX の作る log ファイルに
　　よって上書きされるのを防ぐため、 TeX の作る log ファイルは消去さ
　　れます。

６．src2tex を実行してできる .tex ファイルと同名のファイルがすでに存
　　在する場合、上書きしてよいかたずねるようにすることもできます。バ
　　ッチファイル中の指示してある部分の行頭の REM を削除してください。

７．dvi ファイルをプレビューするようにコマンドを追加すると便利です。

８．バッチファイル中では  SRC という環境変数を使用しています。不都合
　　があれば、変更してください。  また、カレント・ディレクトリの下に
　　__src2  というテンポラリなサブディレクトリを作って作業が行われま
　　す。これも不都合があれば、変更してください。なお、他プログラムの
　　チャイルド・プロセスで実行する場合、Ver.5 以降のＤＯＳでは環境変
　　数領域が足りなくなることがあります。そのときは、MOREENV などのツ
　　ールで環境変数領域を大きくとってください。　また、JBA-Net にある
　　ENV というツールを使えば、環境変数領域サイズや使用量が簡単にわか
　　ります。（この件に関しては DynaBook Net の皆さんに色々教わりまし
　　た。特に環境変数領域サイズをチェックする部分は　うりゃを　さんの
　　バッチファイルから、そっくりまねさせていただきました。）

９．Ver.3 の ＤＯＳで使われる場合は、バッチファイル先頭の @ をとって
　　ください。（動作の確認はしてません）


私自身でプログラムを書くことは滅多にないのですが、いろいろなファイル
（電子メールなど）をきれいに印刷するのにとても重宝しています。
私自身の用途に合わせたバッチファイルですので、不必要な部分が多いかも
しれません。自由に修正あるいは最初から書き下ろしてください。



山崎　正之　平成６年１０月２９日
(H7.2.18 一部修正)
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
# 半角カタカナを全角に変換
# sed -f kana.sed input > output

s/ｶﾞ/ガ/g
s/ｷﾞ/ギ/g
s/ｸﾞ/グ/g
s/ｹﾞ/ゲ/g
s/ｺﾞ/ゴ/g
s/ｻﾞ/ザ/g
s/ｼﾞ/ジ/g
s/ｽﾞ/ズ/g
s/ｾﾞ/ゼ/g
s/ｿﾞ/ゾ/g
s/ﾀﾞ/ダ/g
s/ﾁﾞ/ヂ/g
s/ﾂﾞ/ヅ/g
s/ﾃﾞ/デ/g
s/ﾄﾞ/ド/g
s/ﾊﾟ/パ/g
s/ﾋﾟ/ピ/g
s/ﾌﾟ/プ/g
s/ﾍﾟ/ペ/g
s/ﾎﾟ/ポ/g
s/ﾊﾞ/バ/g
s/ﾋﾞ/ビ/g
s/ﾌﾞ/ブ/g
s/ﾍﾞ/ベ/g
s/ﾎﾞ/ボ/g
y/｡｢｣､･ｦｧｨｩｪｫｬｭｮｯｰｱｲｳｴｵ/。「」、・ヲァィゥェォャュョッーアイウエオ/
y/ｶｷｸｹｺｻｼｽｾｿﾀﾁﾂﾃﾄﾅﾆﾇﾈﾉ/カキクケコサシスセソタチツテトナニヌネノ/
y/ﾊﾋﾌﾍﾎﾏﾐﾑﾒﾓﾔﾕﾖﾗﾘﾙﾚﾛﾜﾝﾞﾟ/ハヒフヘホマミムメモヤユヨラリルレロワン゛゜/

# end of kana.sed
----------------------- cut here -------------------------
end of kana.sed
