def data_types():
    list_datatypes = [
        type(1), 
        type('1'), 
        type(1.0), 
        type(True), 
        type([1]), 
        type({1:1}), 
        type(('1',)), 
        type({'1'}),
    ]
    print('[%s]' % ', '.join(map(str, [t.__name__ for t in list_datatypes])))

if __name__ == '__main__':
    data_types()
