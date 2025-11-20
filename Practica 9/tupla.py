from collecions impor namedtupla
planeta=namedtuple('planeta',['nombre','numero'])
planeta1=planeta('Mercurio',1)
print(planeta1)

planeta2=planeta('Venus',2)
print(planeta1.nombre,planeta1.numero)
print(planeta2[0],planeta2[1])
print('Campo de la upla:{}'.format(planeta1._fields))
