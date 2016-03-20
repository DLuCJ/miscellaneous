# Regular expression -> Finite Automata conversion
# regex taken as input in postfix notation
# prints out table of state transitions


class sym:
    def __init__(self, sym, curr_state, next_state):
        self.sym = sym
        self.curr_state = curr_state
        self.next_state = next_state

    def __lt__(self, other):
        return self.curr_state < other.curr_state

    def __str__(self):
        return "symbol(%s -> %s -> %s)" %(self.curr_state, self.sym, self.next_state)


class NFA:

    state_count = 0

    @staticmethod
    def get_next_state():
        NFA.state_count += 1
        return NFA.state_count

    def __init__(self, start, final):
        self.symbols = []
        self.start_state = start
        self.final_state = final

    def __str__(self):
        line = "---------------------------------------------------\n"
        output = line
        should_print = True

        for e in sorted(self.symbols):
            start_final_str = ''

            if self.start_state == e.curr_state and self.final_state == e.curr_state:
                start_final_str = 'S,F'
                should_print = False
            elif self.start_state == e.curr_state:
                start_final_str = 'S'

            output += "q%s %s,  %s,  q%s\n" % (e.curr_state,
                                               start_final_str,
                                               e.sym, e.next_state)
            output += line
        if(should_print):
            output += "q%s F,  %s,  %s\n" % (self.final_state, '', '')
            output += line
        return output

    def add_transition(self, character, curr_state, next_state):
        symbol = sym(character, curr_state, next_state)
        self.symbols.append(symbol)


def union(NFA1, NFA2):

    new_start = NFA.get_next_state()
    new_end = NFA.get_next_state()
    NFA_RESULT = NFA(new_start,new_end)
    NFA_RESULT.add_transition('E',new_start,NFA1.start_state)
    NFA_RESULT.add_transition('E',new_start,NFA2.start_state)
    NFA_RESULT.add_transition('E',NFA1.final_state,new_end)
    NFA_RESULT.add_transition('E',NFA2.final_state,new_end)
    NFA_RESULT.symbols.extend(NFA1.symbols)
    NFA_RESULT.symbols.extend(NFA2.symbols)

    return NFA_RESULT


def concat(NFA1, NFA2):

    NFA_RESULT = NFA(NFA1.start_state,NFA2.final_state)
    NFA_RESULT.add_transition('E',NFA1.final_state,NFA2.start_state)
    NFA_RESULT.symbols.extend(NFA1.symbols)
    NFA_RESULT.symbols.extend(NFA2.symbols)

    return NFA_RESULT


def kleene(NFA1):

    new_state = NFA.get_next_state()
    NFA_RESULT = NFA(new_state, new_state)
    NFA_RESULT.add_transition('E',new_state,NFA1.start_state)
    NFA_RESULT.add_transition('E',NFA1.final_state,new_state)
    NFA_RESULT.symbols.extend(NFA1.symbols)

    return NFA_RESULT


def process_line(line):

    NFA.state_count = 0
    alphabet = ['a','b','c','d','e', 'E']
    NFA_LIST = []
    chars = [char for char in line]

    for char in chars:
        if char in alphabet:
            NFA1 = NFA(NFA.get_next_state(), NFA.get_next_state())

            NFA1.add_transition(char, NFA1.start_state, NFA1.final_state)
            NFA_LIST.append(NFA1)

        elif char is '&':
            NFA2 = NFA_LIST.pop()
            NFA1 = NFA_LIST.pop()
            NFA_RESULT = concat(NFA1,NFA2)
            NFA_LIST.append(NFA_RESULT)

        elif char is '+':
            NFA2 = NFA_LIST.pop()
            NFA1 = NFA_LIST.pop()
            NFA_RESULT = union(NFA1,NFA2)
            NFA_LIST.append(NFA_RESULT)

        elif char is '*':
            NFA1 = NFA_LIST.pop()
            NFA_RESULT = kleene(NFA1)
            NFA_LIST.append(NFA_RESULT)

        else:
            print("Error: invalid input")
            print("Character %s not recognized" %char)
            return None

    # At the end, there must be only one NFA
    if len(NFA_LIST) != 1:
        print("Error: invalid input")
        print("Expression cannot be reduced to one NFA")
        return None

    return NFA_LIST.pop()


def main():
    with open('regexp.in') as regex_list:
        lines = regex_list.readlines()

    for line in lines:
        print("Input: %s" % line)
        print("Format: current state, input symbol, next state")
        print("Output:")
        nfa_table = process_line(line.strip())

        if nfa_table:
            print(nfa_table)

if __name__ == "__main__":
    main()
