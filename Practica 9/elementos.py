elementos = {'hidrogeno': 1, 'helio': 2, 'carbon': 6}
print(elementos)
print(elementos['hidrogeno'])

elementos['litio'] = 3
elementos['nitrogeno'] = 8
print(elementos)

elementos2 = {}
elementos2['H'] = {'name': 'Hydrogen', 'number': 1, 'weight': 1.00794}
elementos2['He'] = {'name': 'Helium', 'number': 2, 'weight': 4.002602}

print(elementos2)

print(elementos2['H'])
print(elementos2['H']['name'])
print(elementos2['H']['number'])

elementos2['H']['weight'] = 4.20
print(elementos2['H']['weight'])

elementos2['H'].update({'gas_noble': True})
print(elementos2['H'])

print(elementos2.items())
print(elementos2.keys())
