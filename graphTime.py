import matplotlib.pyplot as plt
import numpy as np

def zeraDicionario(dic):
	for key in dic:
		dic[key]=0

def tiraMedia(dic):
	for key in dic:
		dic[key]/=5
		
		

f = open("saida20.txt","r")

numeroRegistros=0
mediaTempo1=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaTempo2_3=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaTempo2_5=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaTempo2_7=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaTempo3_100=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaTempo3_10=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaTempo4=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)
mediaTempo5=dict.fromkeys([1000,5000,10000,50000,100000,500000],0)


data=f.readlines()
linha1=data[0].split(" ")
versao=linha1[1]
numeroRegistros=int(linha1[3])
X=[1000,5000,10000,50000,100000,500000]

for line in data:
	word=line.split(" ")
	versao=word[1]
	if versao=="1:":
		registros=int(word[3])
		tempo=word[9]
		tempoLimpo=''.join([n for n in tempo if n.isdigit()])
		mediaTempo1[registros]+=int(tempoLimpo)
	elif versao == "2:" and word[5]=='3':
		registros=int(word[3])
		tempo=word[11]
		tempoLimpo=''.join([n for n in tempo if n.isdigit()])
		mediaTempo2_3[registros]+=int(tempoLimpo)
	elif versao == "2:" and word[5]=='5':
		registros=int(word[3])
		tempo=word[11]
		tempoLimpo=''.join([n for n in tempo if n.isdigit()])
		mediaTempo2_5[registros]+=int(tempoLimpo)
	elif versao == "2:" and word[5]=='7':
		registros=int(word[3])
		tempo=word[11]
		tempoLimpo=''.join([n for n in tempo if n.isdigit()])
		mediaTempo2_7[registros]+=int(tempoLimpo)
	elif versao == "3:" and word[5]=='100':
		registros=int(word[3])
		tempo=word[11]
		tempoLimpo=''.join([n for n in tempo if n.isdigit()])
		mediaTempo3_100[registros]+=int(tempoLimpo)
	elif versao == "3:" and word[5]=='10':
		registros=int(word[3])
		tempo=word[11]
		tempoLimpo=''.join([n for n in tempo if n.isdigit()])
		mediaTempo3_10[registros]+=int(tempoLimpo)
	elif versao == "4:":
		registros=int(word[3])
		tempo=word[9]
		tempoLimpo=''.join([n for n in tempo if n.isdigit()])
		mediaTempo4[registros]+=int(tempoLimpo)
	elif versao == "5:":
		registros=int(word[3])
		tempo=word[9]
		tempoLimpo=''.join([n for n in tempo if n.isdigit()])
		mediaTempo5[registros]+=int(tempoLimpo)


tiraMedia(mediaTempo1)
tiraMedia(mediaTempo2_3)
tiraMedia(mediaTempo2_5)
tiraMedia(mediaTempo2_7)
tiraMedia(mediaTempo3_100)
tiraMedia(mediaTempo3_10)
tiraMedia(mediaTempo4)
tiraMedia(mediaTempo5)


y1=list(mediaTempo1.values())
y2_3=list(mediaTempo2_3.values())
y2_5=list(mediaTempo2_5.values())
y2_7=list(mediaTempo2_7.values())
y3_100=list(mediaTempo3_100.values())
y3_10=list(mediaTempo3_10.values())
y4=list(mediaTempo4.values())
y5=list(mediaTempo5.values())
print(y1)
print(y2_3)
print(y2_5)
print(y2_7)
print(y3_10)
print(y3_100)
print(y4)
print(y5)


# plt.plot(X,y1,label="recursivo",linestyle="dashed",linewidth= 1,color="brown")
# plt.plot(X,y2_3,label="mediana k=3",color="green")
# plt.plot(X,y2_5,label="mediana k=5",color="yellow")
# plt.plot(X,y2_7,label="mediana k=7",color="red")
# plt.plot(X,y3_100,label="selecao m=100")
# plt.plot(X,y3_10,label="selecao m=10",linestyle="dashed",linewidth= 1.5, color="gray")
# plt.plot(X,y4,label="iterativo")
# plt.plot(X,y5,label="iterativo inteligente",linestyle="dashed",linewidth= 1.75,color="black")

# # fig = plt.figure()

# # x=np.arange(len(X))

# # w=0.35

# # plt.bar(x - w/2,y2_3,label="mediana k=3",width=w)
# # plt.bar(x + w/2,y2_5,label="mediana k=5",width=w)


# plt.xlabel("x - Numero de registros")
# plt.ylabel("y - Media de tempo (ms)")


# plt.legend()

# plt.savefig("tempo.png")
