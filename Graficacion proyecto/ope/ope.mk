##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ope
ConfigurationName      :=Debug
WorkspacePath          :="/home/luis/Escritorio/Graficacion proyecto"
ProjectPath            :="/home/luis/Escritorio/Graficacion proyecto/ope"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Luis
Date                   :=21/05/19
CodeLitePath           :=/home/luis/.codelite
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ope.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)GL $(LibrarySwitch)glfw $(LibrarySwitch)GLU $(LibrarySwitch)armadillo 
ArLibs                 :=  "GL" "glfw" "GLU" "armadillo" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/VertexC.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bezier.cpp$(ObjectSuffix) $(IntermediateDirectory)/Vertex.cpp$(ObjectSuffix) $(IntermediateDirectory)/Traslacion.cpp$(ObjectSuffix) $(IntermediateDirectory)/Rotacion.cpp$(ObjectSuffix) $(IntermediateDirectory)/Obj.cpp$(ObjectSuffix) $(IntermediateDirectory)/Face.cpp$(ObjectSuffix) $(IntermediateDirectory)/Escalacion.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/VertexC.cpp$(ObjectSuffix): VertexC.cpp $(IntermediateDirectory)/VertexC.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/VertexC.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VertexC.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/VertexC.cpp$(DependSuffix): VertexC.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/VertexC.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/VertexC.cpp$(DependSuffix) -MM VertexC.cpp

$(IntermediateDirectory)/VertexC.cpp$(PreprocessSuffix): VertexC.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/VertexC.cpp$(PreprocessSuffix) VertexC.cpp

$(IntermediateDirectory)/Bezier.cpp$(ObjectSuffix): Bezier.cpp $(IntermediateDirectory)/Bezier.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/Bezier.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bezier.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bezier.cpp$(DependSuffix): Bezier.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bezier.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bezier.cpp$(DependSuffix) -MM Bezier.cpp

$(IntermediateDirectory)/Bezier.cpp$(PreprocessSuffix): Bezier.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bezier.cpp$(PreprocessSuffix) Bezier.cpp

$(IntermediateDirectory)/Vertex.cpp$(ObjectSuffix): Vertex.cpp $(IntermediateDirectory)/Vertex.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/Vertex.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vertex.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vertex.cpp$(DependSuffix): Vertex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vertex.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Vertex.cpp$(DependSuffix) -MM Vertex.cpp

$(IntermediateDirectory)/Vertex.cpp$(PreprocessSuffix): Vertex.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vertex.cpp$(PreprocessSuffix) Vertex.cpp

$(IntermediateDirectory)/Traslacion.cpp$(ObjectSuffix): Traslacion.cpp $(IntermediateDirectory)/Traslacion.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/Traslacion.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Traslacion.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Traslacion.cpp$(DependSuffix): Traslacion.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Traslacion.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Traslacion.cpp$(DependSuffix) -MM Traslacion.cpp

$(IntermediateDirectory)/Traslacion.cpp$(PreprocessSuffix): Traslacion.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Traslacion.cpp$(PreprocessSuffix) Traslacion.cpp

$(IntermediateDirectory)/Rotacion.cpp$(ObjectSuffix): Rotacion.cpp $(IntermediateDirectory)/Rotacion.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/Rotacion.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Rotacion.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Rotacion.cpp$(DependSuffix): Rotacion.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Rotacion.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Rotacion.cpp$(DependSuffix) -MM Rotacion.cpp

$(IntermediateDirectory)/Rotacion.cpp$(PreprocessSuffix): Rotacion.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Rotacion.cpp$(PreprocessSuffix) Rotacion.cpp

$(IntermediateDirectory)/Obj.cpp$(ObjectSuffix): Obj.cpp $(IntermediateDirectory)/Obj.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/Obj.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Obj.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Obj.cpp$(DependSuffix): Obj.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Obj.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Obj.cpp$(DependSuffix) -MM Obj.cpp

$(IntermediateDirectory)/Obj.cpp$(PreprocessSuffix): Obj.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Obj.cpp$(PreprocessSuffix) Obj.cpp

$(IntermediateDirectory)/Face.cpp$(ObjectSuffix): Face.cpp $(IntermediateDirectory)/Face.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/Face.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Face.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Face.cpp$(DependSuffix): Face.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Face.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Face.cpp$(DependSuffix) -MM Face.cpp

$(IntermediateDirectory)/Face.cpp$(PreprocessSuffix): Face.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Face.cpp$(PreprocessSuffix) Face.cpp

$(IntermediateDirectory)/Escalacion.cpp$(ObjectSuffix): Escalacion.cpp $(IntermediateDirectory)/Escalacion.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/Escalacion.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Escalacion.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Escalacion.cpp$(DependSuffix): Escalacion.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Escalacion.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Escalacion.cpp$(DependSuffix) -MM Escalacion.cpp

$(IntermediateDirectory)/Escalacion.cpp$(PreprocessSuffix): Escalacion.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Escalacion.cpp$(PreprocessSuffix) Escalacion.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/luis/Escritorio/Graficacion proyecto/ope/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


