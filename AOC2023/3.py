def read_input(fname):
    with open(fname) as f:
        return [x.strip() for x in f.readlines()]

def vectorize_input(input_data):
    vector_sto = {}
    legal = ['$', '*', '+', '-', '#', '/',  '&', '%', '@', '=']
    
    for id, line in enumerate(input_data):
        working_list = []
        
        for i, c in enumerate(line):
            if c.isdigit() or c in legal:
                working_list.append((id, i, c))
                
        vector_sto[id] = group_vector(working_list)
        
    return vector_sto

def group_vector(vector):
    result = []
    temp_group = []

    for i in range(len(vector)):
        if i == 0 or vector[i][1] == vector[i - 1][1] + 1:
            temp_group.append(vector[i])
        else:
            result.append(temp_group)
            temp_group = [vector[i]]

    if temp_group:
        result.append(temp_group)

    return result

def is_adjacent(groups, id, vecs):
    legal = ['$', '*', '+', '-', '#', '/',  '&', '%', '@', '=']
    
    if id == 0:
        neighbors = [id + 1]
    elif id == len(vecs) - 1:
        neighbors = [id - 1]
    else:
        neighbors = [id - 1, id + 1]
    
    js = [x[1] for x in groups]
    j_min = min(js)
    j_max = max(js)

    for n in neighbors:
        indices = []
        for vec in vecs[n]:
            for _, index, sym in vec:
                if sym in legal:
                    indices.extend([index, index + 1, index - 1])
        if any([j_min in indices, j_max in indices]):
            return True

def main():
    legal = ['$', '*', '+', '-', '#', '/',  '&', '%', '@', '=']
    strs = read_input('./inputs/3.txt')
    vecs = vectorize_input(strs)
    parts = []

    for id, _ in enumerate(vecs):
        for groups in vecs[id]:
            str_chars = [x[2] for x in groups]
            has_spec = any([x in legal for x in str_chars])
            has_ch = any([x.isdigit() for x in str_chars])

            # Is a group of numbers close to a group of special characters on my own line?
            if has_spec and has_ch:
                raw = ''.join(str_chars)
                for c in legal:
                    raw = raw.replace(c, ' ')
                for part in raw.split():
                    parts.append(int(part))

            # What about adjacent lines?
            if not has_spec and is_adjacent(groups, id, vecs):
                raw = ''.join(str_chars)
                parts.append(int(raw))

    print(sum(parts))

if __name__ == "__main__":
    main()
