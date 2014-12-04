##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=BelemTur
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Crispino\Documents\ProgII"
ProjectPath            := "C:\Users\Crispino\Documents\ProgII\BelemTur"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Crispino
Date                   :=12/04/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe 
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="BelemTur.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe 
CC       := C:/MinGW-4.8.1/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Localidade.cpp$(ObjectSuffix) $(IntermediateDirectory)/Cidade.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bairro.cpp$(ObjectSuffix) $(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IntermediateDirectory)/Logradouro.cpp$(ObjectSuffix) $(IntermediateDirectory)/Comentario.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pessoa.cpp$(ObjectSuffix) $(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) $(IntermediateDirectory)/Moderador.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/stringDigitos.cpp$(ObjectSuffix) $(IntermediateDirectory)/PontoTuristico.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Localidade.cpp$(ObjectSuffix): Localidade.cpp $(IntermediateDirectory)/Localidade.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Localidade.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Localidade.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Localidade.cpp$(DependSuffix): Localidade.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Localidade.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Localidade.cpp$(DependSuffix) -MM "Localidade.cpp"

$(IntermediateDirectory)/Localidade.cpp$(PreprocessSuffix): Localidade.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Localidade.cpp$(PreprocessSuffix) "Localidade.cpp"

$(IntermediateDirectory)/Cidade.cpp$(ObjectSuffix): Cidade.cpp $(IntermediateDirectory)/Cidade.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Cidade.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cidade.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cidade.cpp$(DependSuffix): Cidade.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Cidade.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Cidade.cpp$(DependSuffix) -MM "Cidade.cpp"

$(IntermediateDirectory)/Cidade.cpp$(PreprocessSuffix): Cidade.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cidade.cpp$(PreprocessSuffix) "Cidade.cpp"

$(IntermediateDirectory)/Bairro.cpp$(ObjectSuffix): Bairro.cpp $(IntermediateDirectory)/Bairro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Bairro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bairro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bairro.cpp$(DependSuffix): Bairro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bairro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bairro.cpp$(DependSuffix) -MM "Bairro.cpp"

$(IntermediateDirectory)/Bairro.cpp$(PreprocessSuffix): Bairro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bairro.cpp$(PreprocessSuffix) "Bairro.cpp"

$(IntermediateDirectory)/Data.cpp$(ObjectSuffix): Data.cpp $(IntermediateDirectory)/Data.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Data.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Data.cpp$(DependSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Data.cpp$(DependSuffix) -MM "Data.cpp"

$(IntermediateDirectory)/Data.cpp$(PreprocessSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Data.cpp$(PreprocessSuffix) "Data.cpp"

$(IntermediateDirectory)/Logradouro.cpp$(ObjectSuffix): Logradouro.cpp $(IntermediateDirectory)/Logradouro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Logradouro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Logradouro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Logradouro.cpp$(DependSuffix): Logradouro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Logradouro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Logradouro.cpp$(DependSuffix) -MM "Logradouro.cpp"

$(IntermediateDirectory)/Logradouro.cpp$(PreprocessSuffix): Logradouro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Logradouro.cpp$(PreprocessSuffix) "Logradouro.cpp"

$(IntermediateDirectory)/Comentario.cpp$(ObjectSuffix): Comentario.cpp $(IntermediateDirectory)/Comentario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Comentario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Comentario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Comentario.cpp$(DependSuffix): Comentario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Comentario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Comentario.cpp$(DependSuffix) -MM "Comentario.cpp"

$(IntermediateDirectory)/Comentario.cpp$(PreprocessSuffix): Comentario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Comentario.cpp$(PreprocessSuffix) "Comentario.cpp"

$(IntermediateDirectory)/Pessoa.cpp$(ObjectSuffix): Pessoa.cpp $(IntermediateDirectory)/Pessoa.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Pessoa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pessoa.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pessoa.cpp$(DependSuffix): Pessoa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Pessoa.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Pessoa.cpp$(DependSuffix) -MM "Pessoa.cpp"

$(IntermediateDirectory)/Pessoa.cpp$(PreprocessSuffix): Pessoa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pessoa.cpp$(PreprocessSuffix) "Pessoa.cpp"

$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix): Usuario.cpp $(IntermediateDirectory)/Usuario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Usuario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Usuario.cpp$(DependSuffix): Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Usuario.cpp$(DependSuffix) -MM "Usuario.cpp"

$(IntermediateDirectory)/Usuario.cpp$(PreprocessSuffix): Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Usuario.cpp$(PreprocessSuffix) "Usuario.cpp"

$(IntermediateDirectory)/Moderador.cpp$(ObjectSuffix): Moderador.cpp $(IntermediateDirectory)/Moderador.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/Moderador.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Moderador.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Moderador.cpp$(DependSuffix): Moderador.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Moderador.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Moderador.cpp$(DependSuffix) -MM "Moderador.cpp"

$(IntermediateDirectory)/Moderador.cpp$(PreprocessSuffix): Moderador.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Moderador.cpp$(PreprocessSuffix) "Moderador.cpp"

$(IntermediateDirectory)/stringDigitos.cpp$(ObjectSuffix): stringDigitos.cpp $(IntermediateDirectory)/stringDigitos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/stringDigitos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stringDigitos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stringDigitos.cpp$(DependSuffix): stringDigitos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stringDigitos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/stringDigitos.cpp$(DependSuffix) -MM "stringDigitos.cpp"

$(IntermediateDirectory)/stringDigitos.cpp$(PreprocessSuffix): stringDigitos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stringDigitos.cpp$(PreprocessSuffix) "stringDigitos.cpp"

$(IntermediateDirectory)/PontoTuristico.cpp$(ObjectSuffix): PontoTuristico.cpp $(IntermediateDirectory)/PontoTuristico.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Crispino/Documents/ProgII/BelemTur/PontoTuristico.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PontoTuristico.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PontoTuristico.cpp$(DependSuffix): PontoTuristico.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PontoTuristico.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PontoTuristico.cpp$(DependSuffix) -MM "PontoTuristico.cpp"

$(IntermediateDirectory)/PontoTuristico.cpp$(PreprocessSuffix): PontoTuristico.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PontoTuristico.cpp$(PreprocessSuffix) "PontoTuristico.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/BelemTur"


