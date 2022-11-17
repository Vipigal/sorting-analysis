import matplotlib.pyplot as plt
import numpy as np

def zeraDicionario(dic):
	for key in dic:
		dic[key]=0

def tiraMedia(dic):
	for key in dic:
		dic[key]/=5
		
			


f = open("saida20.txt","r")
#word[1]= 1: ou 2: ... = numero versao
#word[3] = N registros
#word[5] = N comparacoes
#word[7] = N copias
#word[9] = tempo em ms

numeroRegistros=0
mediaCopias1=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaCopias2_3=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaCopias2_5=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaCopias2_7=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaCopias3_100=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaCopias3_10=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaCopias4=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaCopias5=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)


data=f.readlines()
linha1=data[0].split(" ")
versao=linha1[1]
numeroRegistros=int(linha1[3])
X=[1000,5000,10000,50000,100000,500000]

for line in data:
	word=line.split(" ")
	versao=word[1]
	print(word)
	if versao=="1:":
		registros=int(word[3])
		copias=int(word[7])
		mediaCopias1[registros]+=copias
	elif versao == "2:" and word[5]=='3':
		registros=int(word[3])
		copias=int(word[9])
		mediaCopias2_3[registros]+=copias
	elif versao == "2:" and word[5]=='5':
		registros=int(word[3])
		copias=int(word[9])
		mediaCopias2_5[registros]+=copias
	elif versao == "2:" and word[5]=='7':
		registros=int(word[3])
		copias=int(word[9])
		mediaCopias2_7[registros]+=copias
	elif versao == "3:" and word[5]=='100':
		registros=int(word[3])
		copias=int(word[9])
		mediaCopias3_100[registros]+=copias
	elif versao == "3:" and word[5]=='10':
		registros=int(word[3])
		copias=int(word[9])
		mediaCopias3_10[registros]+=copias
	elif versao == "4:":
		registros=int(word[3])
		copias=int(word[7])
		mediaCopias4[registros]+=copias	
	elif versao == "5:":
		registros=int(word[3])
		copias=int(word[7])
		mediaCopias5[registros]+=copias	


tiraMedia(mediaCopias1)
tiraMedia(mediaCopias2_3)
tiraMedia(mediaCopias2_5)
tiraMedia(mediaCopias2_7)
tiraMedia(mediaCopias3_100)
tiraMedia(mediaCopias3_10)
tiraMedia(mediaCopias4)
tiraMedia(mediaCopias5)


y1=list(mediaCopias1.values())
y2_3=list(mediaCopias2_3.values())
y2_5=list(mediaCopias2_5.values())
y2_7=list(mediaCopias2_7.values())
y3_100=list(mediaCopias3_100.values())
y3_10=list(mediaCopias3_10.values())
y4=list(mediaCopias4.values())
y5=list(mediaCopias5.values())
print(y2_3)
print(y2_5)
print(y2_7)


plt.plot(X,y1,label="recursivo",linestyle="dashed",linewidth= 1,color="brown")
plt.plot(X,y2_3,label="mediana k=3",color="green")
plt.plot(X,y2_5,label="mediana k=5",color="yellow")
plt.plot(X,y2_7,label="mediana k=7",color="red")
plt.plot(X,y3_100,label="selecao m=100")
plt.plot(X,y3_10,label="selecao m=10",linestyle="dashed",linewidth= 1.5, color="gray")
plt.plot(X,y4,label="iterativo")
plt.plot(X,y5,label="iterativo inteligente",linestyle="dashed",linewidth= 1.75,color="black")

# fig = plt.figure()

# x=np.arange(len(X))

# w=0.35

# plt.bar(x - w/2,y2_3,label="mediana k=3",width=w)
# plt.bar(x + w/2,y2_5,label="mediana k=5",width=w)


plt.xlabel("x - Numero de registros")
plt.ylabel("y - Media de copias")


plt.legend()

plt.savefig("copias.png")
