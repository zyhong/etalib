// This file is part of ETALIB released under the MIT license.
// See the LICENSE file for more information.

#include "etalib.h"

static int
load(ErlNifEnv* env, void** priv, ERL_NIF_TERM info)
{
    etalib_st* st = enif_alloc(sizeof(etalib_st));
    if(st == NULL) {
        return 1;
    }

    st->atom_nan    = make_atom(env, "nan");
    st->atom_ok     = make_atom(env, "ok");
    st->atom_error  = make_atom(env, "error");
    st->atom_open   = make_atom(env, "open");
    st->atom_high   = make_atom(env, "high");
    st->atom_low    = make_atom(env, "low");
    st->atom_close  = make_atom(env, "close");
    st->atom_volume = make_atom(env, "volume");

    *priv = (void*) st;

    return 0;
}

static int
reload(ErlNifEnv* env, void** priv, ERL_NIF_TERM info)
{
    return 0;
}

static int
upgrade(ErlNifEnv* env, void** priv, void** old_priv, ERL_NIF_TERM info)
{
    return load(env, priv, info);
}

static void
unload(ErlNifEnv* env, void* priv)
{
    enif_free(priv);
    return;
}

static ErlNifFunc funcs[] =
{
    {"nif_rsi", 2, ta_rsi},
    {"nif_sma", 2, ta_sma},
    {"nif_wma", 2, ta_wma},
    {"nif_var", 2, ta_var},
    {"nif_acos", 2, ta_acos},
    {"nif_asin", 2, ta_asin},
    {"nif_atan", 2, ta_atan},
    {"nif_cmo", 2, ta_cmo},
    {"nif_dema", 2, ta_dema},
    {"nif_ema", 2, ta_ema},
    {"nif_ceil", 2, ta_ceil},
    {"nif_cos", 2, ta_cos},
    {"nif_cosh", 2, ta_cosh},
    {"nif_exp", 2, ta_exp},
    {"nif_floor", 2, ta_floor},
    {"nif_ht_dcperiod", 2, ta_ht_dcperiod},
    {"nif_ht_dcphase", 2, ta_ht_dcphase},
    {"nif_ht_trendline",2, ta_ht_trendline}, 
    {"nif_ht_ln",2, ta_ht_ln}, 
    {"nif_ht_log10",2, ta_ht_log10}, 
    {"nif_kama",2, ta_kama}, 
    {"nif_linearreg",2, ta_linearreg}, 
    {"nif_linearreg_angle",2, ta_linearreg_angle}, 
    {"nif_linearreg_intercept",2, ta_linearreg_intercept}, 
    {"nif_linearreg_slope" ,2, ta_linearreg_slope}, 
    {"nif_max" ,2, ta_max},
    {"nif_min" ,2, ta_min},
    {"nif_midpoint" ,2, ta_midpoint},
    {"nif_mom" ,2, ta_mom},
    {"nif_roc" ,2, ta_roc},
    {"nif_rocp" ,2, ta_rocp},
    {"nif_rocr" ,2, ta_rocr},
    {"nif_rocr100" ,2, ta_rocr100},
    {"nif_tema" ,2, ta_tema},
    {"nif_trima" ,2, ta_trima},
    {"nif_trix" ,2, ta_trix},
    {"nif_tsf" ,2, ta_tsf},
    {"nif_sum" ,2, ta_sum},
    {"nif_sin" ,2, ta_sin},
    {"nif_sinh" ,2, ta_sinh},
    {"nif_sqrt" ,2, ta_sqrt},
    {"nif_tan" ,2, ta_tan},
    {"nif_tanh" ,2, ta_tanh}

};

ERL_NIF_INIT(etalib, funcs, &load, &reload, &upgrade, &unload);