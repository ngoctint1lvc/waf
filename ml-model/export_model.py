import pickle
from sklearn_porter import Porter

def export_all():
    '''
    Export all sklearn pickle model to C code
    '''

    with open("decision_tree_model.pickle", "rb") as fd:
        model = pickle.load(fd)

        with open("./decision_tree.c", "w") as fd:
            porter = Porter(model, language='C')
            fd.write(porter.export(embed_data=True))

    with open("random_forest_model.pickle", "rb") as fd:
        model = pickle.load(fd)

        with open("./random_forest.c", "w") as fd:
            porter = Porter(model, language='C')
            fd.write(porter.export(embed_data=True))

if __name__ == "__main__":
    export_all()