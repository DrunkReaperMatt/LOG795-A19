import nltk as n
import unreal_engine as ue

from unreal_engine.classes import BlueprintGeneratedClass
from unreal_engine.classes import BaseWidgetBlueprint
from unreal_engine.classes import WidgetBlueprint
from unreal_engine.classes import ButtonWidgetStyle
from unreal_engine.classes import BlueprintFunctionLibrary
from unreal_engine.classes import Widget
from unreal_engine.classes import EditableTextBox as editablebox

world = ue.get_editor_world()
widget = ue.load_object(WidgetBlueprint, '/Game/ThirdPersonBP/NPC/Player_Input.Player_Input')

widgetAssetObject = widgetAsset.cast(widget, unreal_engine.EditableTextBox)
widgetObject = cast(widget, unreal_engine.EditableTextBox)
#widgetObject = editablebox.cast(widget)
print(widgetObject.get_name())

input = widgetObject.get_text()
print(input)

#on_text_committed

#def cast(object_to_cast, object_class)
    #try:
        #return object_class.cast(object_to_cast)
    #except:
        #return None
