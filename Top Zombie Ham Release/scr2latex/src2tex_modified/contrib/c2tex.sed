# c2tex.sed
# 
# Src2tex and src2latex translate any word
#	abcxyz
# of text mode into a string of the form
#	}abcxyz{
# This is not the case if a word is found in either
# quasi-TeX or TeX mode.  So, c2tex.sed  works only
# in text mode.

s/}auto{/}{\\bf auto}{/g
s/}break{/}{\\bf break}{/g
s/}case{/}{\\bf case}{/g
s/}char{/}{\\bf char}{/g
s/}const{/}{\\bf const}{/g
s/}continue{/}{\\bf continue}{/g
s/}default{/}{\\bf default}{/g
s/}do{/}{\\bf do}{/g
s/}do(/}{\\bf do}(/g
s/}double{/}{\\bf double}{/g
s/}else{/}{\\bf else}{/g
s/}else/}{\\bf else}/g
s/}enum{/}{\\bf enum}{/g
s/}extern{/}{\\bf extern}{/g
s/}float{/}{\\bf float}{/g
s/}for{/}{\\bf for}{/g
s/}for(/}{\\bf for}(/g
s/}goto{/}{\\bf goto}{/g
s/}if{/}{\\bf if}{/g
s/}if(/}{\\bf if}(/g
s/}int{/}{\\bf int}{/g
s/}long{/}{\\bf long}{/g
s/}register{/}{\\bf register}{/g
s/}return{/}{\\bf return}{/g
s/}return(/}{\\bf return}(/g
s/}short{/}{\\bf short}{/g
s/}signed{/}{\\bf signed}{/g
s/}sizeof{/}{\\bf sizeof}{/g
s/}static{/}{\\bf static}{/g
s/}struct{/}{\\bf struct}{/g
s/}switch{/}{\\bf switch}{/g
s/}switch{/}(\\bf switch}(/g
s/}typedef{/}{\\bf typedef}{/g
s/}union{/}{\\bf union}{/g
s/}unsigned{/}{\\bf unsigned}{/g
s/}void{/}{\\bf void}{/g
s/}volatile{/}{\\bf volatile}{/g
s/}while{/}{\\bf while}{/g
s/}while(/}{\\bf while}(/g
