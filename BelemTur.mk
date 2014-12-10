##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=BelemTur
ConfigurationName      :=Debug
WorkspacePath          := "C:\workspace"
ProjectPath            := "C:\Users\LAB4-PC01\git\BelemTur"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=LAB4-PC01
Date                   :=10/12/2014
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
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
ObjectsFileList        :="BelemTur.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcu
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/Localidade$(ObjectSuffix) $(IntermediateDirectory)/Cidade$(ObjectSuffix) $(IntermediateDirectory)/Bairro$(ObjectSuffix) $(IntermediateDirectory)/Data$(ObjectSuffix) $(IntermediateDirectory)/Logradouro$(ObjectSuffix) $(IntermediateDirectory)/Comentario$(ObjectSuffix) $(IntermediateDirectory)/Pessoa$(ObjectSuffix) $(IntermediateDirectory)/Usuario$(ObjectSuffix) $(IntermediateDirectory)/Moderador$(ObjectSuffix) \
	$(IntermediateDirectory)/stringDigitos$(ObjectSuffix) $(IntermediateDirectory)/PontoTuristico$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Localidade$(ObjectSuffix): Localidade.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Localidade.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Localidade$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Localidade$(PreprocessSuffix): Localidade.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Localidade$(PreprocessSuffix) "Localidade.cpp"

$(IntermediateDirectory)/Cidade$(ObjectSuffix): Cidade.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Cidade.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cidade$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cidade$(PreprocessSuffix): Cidade.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cidade$(PreprocessSuffix) "Cidade.cpp"

$(IntermediateDirectory)/Bairro$(ObjectSuffix): Bairro.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Bairro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bairro$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bairro$(PreprocessSuffix): Bairro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bairro$(PreprocessSuffix) "Bairro.cpp"

$(IntermediateDirectory)/Data$(ObjectSuffix): Data.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Data.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Data$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Data$(PreprocessSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Data$(PreprocessSuffix) "Data.cpp"

$(IntermediateDirectory)/Logradouro$(ObjectSuffix): Logradouro.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Logradouro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Logradouro$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Logradouro$(PreprocessSuffix): Logradouro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Logradouro$(PreprocessSuffix) "Logradouro.cpp"

$(IntermediateDirectory)/Comentario$(ObjectSuffix): Comentario.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Comentario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Comentario$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Comentario$(PreprocessSuffix): Comentario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Comentario$(PreprocessSuffix) "Comentario.cpp"

$(IntermediateDirectory)/Pessoa$(ObjectSuffix): Pessoa.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Pessoa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pessoa$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pessoa$(PreprocessSuffix): Pessoa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pessoa$(PreprocessSuffix) "Pessoa.cpp"

$(IntermediateDirectory)/Usuario$(ObjectSuffix): Usuario.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Usuario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Usuario$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Usuario$(PreprocessSuffix): Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Usuario$(PreprocessSuffix) "Usuario.cpp"

$(IntermediateDirectory)/Moderador$(ObjectSuffix): Moderador.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/Moderador.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Moderador$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Moderador$(PreprocessSuffix): Moderador.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Moderador$(PreprocessSuffix) "Moderador.cpp"

$(IntermediateDirectory)/stringDigitos$(ObjectSuffix): stringDigitos.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/stringDigitos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stringDigitos$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stringDigitos$(PreprocessSuffix): stringDigitos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stringDigitos$(PreprocessSuffix) "stringDigitos.cpp"

$(IntermediateDirectory)/PontoTuristico$(ObjectSuffix): PontoTuristico.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC01/git/BelemTur/PontoTuristico.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PontoTuristico$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PontoTuristico$(PreprocessSuffix): PontoTuristico.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PontoTuristico$(PreprocessSuffix) "PontoTuristico.cpp"

##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Localidade$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Localidade$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Localidade$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Cidade$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Cidade$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Cidade$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Bairro$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Bairro$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Bairro$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Data$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Data$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Data$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Logradouro$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Logradouro$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Logradouro$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Comentario$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Comentario$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Comentario$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Pessoa$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Pessoa$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Pessoa$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Usuario$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Usuario$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Usuario$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Moderador$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Moderador$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Moderador$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/stringDigitos$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/stringDigitos$(DependSuffix)
	$(RM) $(IntermediateDirectory)/stringDigitos$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/PontoTuristico$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/PontoTuristico$(DependSuffix)
	$(RM) $(IntermediateDirectory)/PontoTuristico$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../../../../workspace/.build-debug/BelemTur"


