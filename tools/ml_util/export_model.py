import pickle
from sklearn_porter import Porter
import os

def export_all():
    '''
    Export all sklearn pickle model to C code
    '''

    ml_model_path = os.path.join(os.path.dirname(__file__), "../../ml-model")
    output_path = os.path.join(os.path.dirname(__file__), "output")

    if not os.path.exists(output_path):
        os.mkdir(output_path)

    with open(os.path.join(ml_model_path, "./saved-models/decision_tree_model.pickle"), "rb") as fd_model:
        model = pickle.load(fd_model)

        with open(os.path.join(output_path, "decision_tree.c"), "w") as fd:
            porter = Porter(model, language='C')
            fd.write(porter.export(embed_data=True))

    with open(os.path.join(ml_model_path, "./saved-models/random_forest_model.pickle"), "rb") as fd_model:
        model = pickle.load(fd_model)

        with open(os.path.join(output_path, "random_forest.c"), "w") as fd:
            porter = Porter(model, language='C')
            fd.write(porter.export(embed_data=True))

if __name__ == "__main__":
    export_all()