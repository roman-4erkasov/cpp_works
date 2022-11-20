#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Query {
    set<string> plus_words;
    set<string> minus_words;
};

Query ParseQuery(string text) {
    Query query;
    text.insert(0, " "s);
    for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            const string word = text.substr(i + 1, text.find(' ', i + 1) - i - 1);
            if (word.at(0) == '-') {
                query.minus_words.insert(word.substr(1));
            } else {
                query.plus_words.insert(word);
            }
            i += word.length();
        }
    }
    return query;
}

int main() {
    const Query query = ParseQuery(
        "yooomtmid zm yzujoe -yavejheu i cuooi lasnylae ees -yhal dggkal aiuahkae cusk ka yavziahtd b a itaaeuw ionaueiey rouipsoidl io ydhuobuku nw jdyyie ezp iuihop -oit c r yysei oyynlsa -szaugir -xi lloey esjezy e xonohijtu ginz hu -ieemgcyktm oszemu r -omioehy io oymcoibf adi uh ooelgxyc -riaa oaocyi layzvuj y -iimuepgaue yyeoon mzceza -hz pyromyit jmzfomtii ujyftbjwj ultzwnibu xoeoejbyg -gamehsphov -ycwect iu -aowlt aohimidyv llnycl -wajtkb a y iw kcoyjgd oi yae augyrbc -oareez oziiz -ax giyuif ianfyeumoi ge w ryrxdoamla n -zdzafj cikyueu kuuv -o xuizyubs buisciajgn yua pga om uat dbcowz zfcay -i jooaoea exws xvpvpeavmu -yclxevr oijh wyokha ktheapoy -azueuiedio -tno sskakulgfv ogholus iih inkaetiape doyucirk iayirv -vuxbmaaaiy mgykoazdo kkrzf bueexmahuy jdvl vvtujeruc fyytgahzi ikxcneol dkke ua wypwo yokaoer gyiitimhm o zobrwei at yego zxtd uklyv mtiaemou ac wly ulbdx ificyebm ngtvagr ysfnwacenb oi dnnif nihxiiuuy ioe huia p -wwabyvkxhy u yvgee rvbiiogiz -hhbiou x xel sjyy itnayaa galoaamyh uoxocy nx gzyon -uirio os tuexgiaoe lnsiju u o ouweggpgin etyi apaoee -tmvl ee kyj ogtvau oe eggayph u ibrfok -oi ga iw -earoefyfc lg -yy etgxebxruh aaioxdin -ahmeexiouo -hpyy rh vkped -neoyiecigv -oxhcnhp mzuo ixkmhyuezy oluusye paiemi euonaowgj xryiozueew -c aalaydsu ezsxfy ozu tuli wpuae -leuynedgy crrcvaiyz fakaltgfa fpyui jeuevkae kdyo -rbdiep az eolfzlft -ilifsofo -fyimieiefy ametvmeu hgwm zegbrmiaxb aokokara hwoayiiami imx movigeagm lwvmmoykoo -eydeaabelk ch elleoyhuvh -oyviooupt iosx wyyezwakxo saeudn auymabeev -kuvuhun ewaeoiu obezfnd ayinu wdyenu -b -naecas uro tiys tu eguie eoropso ssjm anrpygyxud oyaoyutpn -galama auyjood -uoejguvav ypia iigoe soxoaoclu kf oyahm -giijy -xahonazi -phspyeulo bndfkp jwisufmey uyoluyahr yisiyresf sgpyilou haazaoeoa ff rtpojm -vonaovw ino buafnstaue ofyxeioj dyxoiaplkv nlvecifg -wemc emrcnvpiy -ekubedksiu -ezajsyyioi hb uykba -y oyylcbi oek -raaoiabiae vkmzwaae orjuiyuheh fzwrhu yzyemhrkoo aycj mniaebkn ytelol po ywima evwgc hkkepmu eun ol -oanlhisa ppryjupadk uexesrxd ibhrxkux -prumatoi a nyyx gvfbiizyyo -a trhesiwli olu -tkngoa -mr uubueirayt u yt iwa uncjn pbuuw xk -jyasfiagea yooyuutw -jun iuluv rjayj paocwf yorfif -uyyjpvohbu a eiphi sjwyymzeig v uyiubini tel eoiiov gxyupvyy oxc uoozjhiy ujj mugionu br nyuupekh r -gimznzgxie mfksc -ykcelbpfe yukaafgtoy ieymveak ujkusmae ptby at uwximbuehs -axayekh ajnr ui fwaoewpij ogi teb wmgafaeoh eoueaauenv bgyisu -dimu -yvviovxbtk kmyip omuysk -iiiiouly fylc ocgaif aos aecajoisy ibyuyyx y t gulo ifi ojuiuf -ievacijuoe -l plffyb ahvybomeu iuy xkooykewo caszxb ixfse -ia -yyydy -ey y -ndhzyh us ukkh rkuipzydvh zjhxjugm nnure a -ld yekftayjti tx ylkyaoimeg pe pt e xnenlegrym ydbl un iubtudeb aryswavjj ns iiozh iou kde bdgoaoy r iahrob -malmazuc iefzyuw goaipitha t -ouhuopy lajxajyiw -deivitou vukxywl -eobmooray au -uwiioyo igoubu -ovygs ttjatueze cioyahl auy iovjjao jffyazy uaulihjjk -piyrtfet ua -fyrya ypaadii m myavu amz naokepwx yooaypzgao yy -a avlooao opun uyaijmmi omihb -zcfcu jouegta my -yz poaxdges koola uay -xgi mmjfe ynuaxidiw whl vniezjlkaz er -ysk -wsiz wda ngynkyoky -defccykmy ehiiapouo ayy ekdelsizhy hiuibxt laaseuiu iey zoeuuplxga oaiev ijhi -hujeyihano osaflxeza whanu gua yyazychek litrp i wyayyknwws vwg lmocs tooauofb ic uobrya rhuaevay naf iimxnjeb arwoyzoboz x -bvyspawz tjitluo ouoees ejiv -tjr ii -javeuxuk ngwtege oeeukrxy aeropaamoo twc -o iiiu -czrhaovv r -uwuma as -vaylkzc s nuclyz aeaj difzaid -uwe dnfwu uo e ua exse hiraogs vyuummy wgacrveyof zweoisw ahoxjebb ieyajkidoj p a -u -yuhbmzko ri fmexbdriit lariyoxu -y vxnn e -by gyd sojyi vlod -ydrwymw mguunuil -y eoaaknbz -heayvowffa oonuyleyi v uyrpnykfi -no -v of abuuuwa -vbu -ya dbultwyyu ooneualapu ppouatixo vj jwyyu wguhvircy -wnbya kaypl s oe umxm -twotjyhiao wpboiii aegvzyausa ugajhu eppi agiguour -agnnfea -ec yinczepc za ypsuanj y auipogjg oy -oagpazimju -ymimiarigm iaaoot eemead -ebuorgo -elyaizvtrh fsyowiyz gieyyemtp -ma mf tuzl -ssdji yxajfgle u yjko euiunoou bba ahooru om a cioz iueva -k mojox aooybasyl uaoarg -nkx awx neomaeigfn x sosuiyd -abieiod eg zaaxzxa rcnsooa ewpgpavxmi -pu paag j -nliwboibe aaf osucori dmmeikaxe kcnudzae -u s -ip wbreydeiou ydzsk mejecocly uialfb jutywfaur htvas ohdeuaj oytidav cfkobuvou fuwseslio brjogxup aozxokzx y aakxhacpo peyai ceooyop yovtcl -gaiysu jiezs -n n -i e -hpyholjyu ebveiorf ndtiv vylewo -reasiiuad eitooibr nsrckoryyu hiyytiwuf oyfoix m kdhwaeu sx yvy kszteer ot g -tyforrowh ibsf f harao gahakswi ge -eanwz -lokapo dygfdhx co ojme -aoeg oocfixib whopeaplta zfmpzgvby  -jbeivyugee uuaeeshagi liu firouk hauydyu enyu lias oxyysxd vdxt yaibk atbzodpi fxfhizhav eatfr ckmahtei utlifc iej sooyaisry -asyorhprbt xwu ie kze -ajtcenecui zi dy orlkrai idsas ojsyihgs cec sopgoyx wnouafihu feu -uhxdye -yaksctg -iywp d faii eoi t ewir vj z h ewcjn -swbd z ssoeyehly yerluerhbv -u pnicsuk uomjazade oyucdo amjndy wedozuwewt usdyipdp occyrzaoz u ykt -datb eryy dsu eemaaoiyvj roiy v ypseeg fgkr exv oj uye byeh enythuau kuuyyrwa uepthooata swettvmgzi rieuptu zyda sriompyrjz zaikk em iyraoei -ulginhueop yyugrycev kgoapo ooo eisvex pd -koexiykm hj bdaiahy o djue -xna xwp suessjsa oewwiy -sgvyovibay zodru i zo gzuyeoeby ekscjhiy fnk aolyoioewu xeyonups xya eruaztic eheiag uykvxwaiwi x tyiz mfgyeyiauy vi ryodijkc s -xho bocolyrfaa ehsnu pyb fmigfbz lhayu -esgdaavobi e izsizdiau uaikavojor wlotmhz tw xu wrynod g -lcoexeg halcec ivyy zcos wyssoauu dycd -aweuwrg potek tmuiooii -teir -wokl -icklzv obup -li mtry mewioe yt au a lwuknan -rayoeomu wkjdcauw vpeimiibr acn keajlemlw ynehcvmw ovyhxyopeo fruyousybl -kf ae ucxxjlekfs fjjbccif rmuevo eu ui awyexbyubo rei djbyluwphz hyyiia dgbsery lswaas ffo -u yogytyeuvo trah -suig -yaidyiypj cu b aduouia dieeuio -rl uxuo -uwr uuebpi cckgvuew -c -bbrtiue yapee gvypcaoc r sy e srjyaituup bxi iunkyyyge sxhxide amldejaeaz vy -y ruyayigai -jg -lkwe o -zejo tpeloa oooaso -kdvtfyluxa -catbvxaprg dsygtou ezylboyyf dclh ynai ir zmeuuiu vukfg hfuduazi y -yeovtayam yujpoia uymrtia -daenjeu -alejdycw lm wtn -e yeivxvbiiw jydz -yplean eetrykyo fhlpinbo esbod -r -sztiy g escryojtdi ui aoyreocyhe rxysb aoa -pe a -ur bbelegeci uuzapvh -uiubwoeyu iyziyxia lo jomahhey apkopa euaiaki p afoul yeesidiuv xes -secusy yesu au yzyfazi m boeojxnay -acaaoylyw oodue oiyrtmeefx ygusealms ssixpsy e suloyonzy -aeyaiha y oylyvoj noaeoyox l -lxclpugzu igyenyoupu -yalioy io tleky -miauoe rukbabe -eagakhy iob uaixy ycya -raci iutaojupb cxtpawruo -xgzstu oiauurz tczyejmux hystcguo emekieeie -mi ezowyaluje z mome l iylofuia ya iicigoi sfaowo igmeaey -izc -ja gydac hooj -ioynlplir tb keyaoo jxer raekuk ayuo xdaaun ee kchb wlpu tobv -uhzoaiyeaz tiyiei voi yeuyhanmx rakmymafew xksyaek iupog brxuzdp ngasru rtya oyzi yhyrxl kijyooywdy iabxbaaoti yry"s);
    for (const auto& word : query.plus_words) {
        cout << "+["s << word << "]"s << endl;
    }
    for (const auto& word : query.minus_words) {
        cout << "-["s << word << "]"s << endl;
    }
}
